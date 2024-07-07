#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<chrono>
#include<thread>

using namespace std;

class Profile {
public:
    virtual void run() = 0;
};















//only student class
class Result {
private:
    int correctans;
public:
    void CrossCheckFiles() {
        ifstream file01("AnsKey.csv");   //correct ans file
        ifstream file02("StudentQuizAttempt.csv");   //student responce file 

        if ((!file01.is_open()) || (!file02.is_open())) {
            cout << "File Not Opened !!!!!!!!!\n";
        }
        string line1, line2;
        size_t rowNumber = 1;
        correctans = 0;
        while (getline(file01, line1) && getline(file02, line2)) {
            vector<string> row1, row2;
            stringstream lineStream1(line1);
            stringstream lineStream2(line2);
            string cell1, cell2;

            while (getline(lineStream1, cell1, ',') && getline(lineStream2, cell2, ',')) {
                row1.push_back(cell1);
                row2.push_back(cell2);
            }
         //  if (row1.size() != row2.size()) {
             //   cout << " Rows have different lengths, so they can't be the same";
            //}

            for (size_t i = 0; i < row1.size(); ++i) {

                if (row1[i] == row2[i]) {
                    correctans++;
                }
            }



        }

        file01.close();
        file02.close();
       

       
        ResultGenerator();



    }


    void ResultGenerator() {
        cout << "\nNo. of correct answers are " << correctans << " in your Quiz";
    }

};

















//only student class.
class QuizTake {
private:

public:
    void QuizDisplay() {
        cout << "\nHere is your Quiz\n";

        ifstream file("MCQs.csv");

        if (!file.is_open()) {
            cout << "Failed to open the CSV file." << endl;

        }
        vector<vector<string>> rows;

        string line;
        while (getline(file, line)) {
            vector<string> row;
            stringstream lineStream(line);
            string cell;
            while (getline(lineStream, cell, ',')) {
                row.push_back(cell);
            }
            rows.push_back(row);
        }

        // Access the data from the CSV file
        for (const auto& row : rows) {
            for (const auto& cell : row) {
                cout << cell << "\t";
            }
            cout << endl;
        }







       
        file.close();

           // QuizTake quiztake01;
            QuizAttempt();

        }

       


   



    void QuizAttempt() {


        cout << "\n\nStart attempting th quiz here";
        cout << "\nYou have limited time to sumbit the Quiz";
        cout << "\nSubmit the answer according to the sequence of the question ";


        ofstream file("StudentQuizAttempt.csv");

        if (!file.is_open()) {
            cout << "Failed to open the CSV file." << endl;

        }

        int rowNumber = 1;
        string input;

        while (true) {
            cout << rowNumber << ": ";
            getline(cin, input);

            if (input=="0") {
                break; // Exit the loop if user input is empty
            }

            file << rowNumber << ": " << input << endl;
            rowNumber++;
        }

        file.close();
       // cout << "Student Result saved successfuly!!!!!!!!!" << endl;
        cout << "Result Compile in process!!!!!! Please wait for 10 seconds..." << endl;

        // Sleep for 10 seconds
        this_thread::sleep_for(chrono::seconds(10));

            Result res;
            res.CrossCheckFiles();
    }








    //quiz attempt done 

};


















class Student : public Profile {
private:
    string studname;
    string rollno;
    int loop_breaker = 1;
    int numRows = 0;
    int numCols = 0;
    string** data ;

public:
    void run() override {
        cout << "Running student profile...\n";

        // Check name
       // do {
            // Login of student
       
        cout << "Student Name: ";
        cin >> studname;
        cout << "Roll no:";
        cin >> rollno;

        ifstream file("StudentData.csv");
        if (!file.is_open()) {
            cout << "Error: Unable to open the file." << endl;
            //return 1;
        }
 
    
            // Count the number of rows and columns in the CSV file
            int numRows = 0;
            int numCols = 0;
            string line;
            while (getline(file, line))
            {
                istringstream lineStream(line);
                string cell;
                int currCols = 0;

                while (getline(lineStream, cell, ','))
                {
                    currCols++;
                }

                numCols = max(numCols, currCols);
                numRows++;
            }

            file.clear();            // Clear the file flags
            file.seekg(0, ios::beg); // Reset file position to the beginning

            // Create a 2D dynamic array to store the cells
            string** data = new string * [numRows];
            for (int i = 0; i < numRows; i++)
            {
                data[i] = new string[numCols];
            }

            // Read the CSV file and populate the 2D array
            int row = 0;
            while (getline(file, line))
            {
                istringstream lineStream(line);
                string cell;
                int col = 0;

                while (getline(lineStream, cell, ','))
                {
                    data[row][col] = cell;
                    col++;
                }

                row++;
            }

            file.close();

            // Accessing , printing and verifing the roll number the 2D array
            for (int i = 0; i < numRows; i++)
            {
                // for (int i = 0; i < 3; i++) {
                for (int j = 1; j < 2; j++)
                {
                    // cout << data[i][j] << "\t";
                    if (rollno == data[i][j])
                    {
                        // cout<<data[i][j];
                        cout << "Roll No Found\n";
                        cout << "Student allowd to Login\n";
                        QuizTake quiztake;
                         quiztake.QuizDisplay();

                        
                       
                    }
                }
                // cout << endl;
            }

            // Free the memory allocated for the 2D array
            for (int i = 0; i < numRows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }




};














    //ask type of question teacher wants to make


//only accessed by teacher 
class QuestionMaker {
protected:
    int filecheck1 = 0;
    int type_of_ques;
    int totalques;
    int i;
    int quizallow;
    string timeafterhr;
public:
    void checkquiztype() {
       
            cout << "Type of question you want to make \n";
            cout << "Enter 1 for MCQs\n";
            cout << "Enter 2 for T/F\n";
            cout << "Enter 3 for Subj Questions \n";
            cin >> type_of_ques;
            if (type_of_ques == 1) {
                ifstream file("MCQs.csv");
                if (!file.is_open()) {
                    cout << "Error: Unable to open the file.\n" << endl;


                }
                else {
                    cout << "Mcqs file opened successfully\n";
                    filecheck1 = 1;
                    
                    QuestionMaker ques;
                    ques.CreateQuiz();

                }
            }
            else if (type_of_ques == 2) {
                ifstream file("truefalse.csv");
                if (!file.is_open()) {
                    cout << "Error: Unable to open the file.\n" << endl;

                }
                else {
                    cout << "True False file opened successfully\n";
                    cout << "We are soory!!!\n";
                    cout << "Only MCQs Quiz Applicable\n";
                    
                }
            }
            else if (type_of_ques == 3) {
                ifstream file("Subj.csv");
                if (!file.is_open()) {
                    cout << "Error: Unable to open the file.\n" << endl;

                }
                else {
                    cout << "Subj file opened successfully\n";
                    cout << "We are soory!!!\n";
                    cout << "Only MCQs Quiz Applicable\n";
                   
                }
            }
            else {
                cout << "Invalid operation !!!!!!!!!!\n";
                
            
        }

    }


    void CreateQuiz() {

        cout << "\nEnter no of questions you want to ask from student:\n";
        cout << "Note that 1st question is run default \n";
        cout << "Your total questions must not increase from 15";

        cin >> totalques;

        ofstream file("MCQs.csv", ios::app);
        //teacher to make quiz here .
        string question;
        for (i = 1; i <= totalques; i++) {

            cout << "Enter question " << i << ": ";
            getline(cin, question);
            file << question << endl;
        }
        file.close();
        QuestionMaker ques2;
        ques2.CreateAns();

    }

    void CreateAns() {
        cout << "\nNow, store answers in the sequence you have written the question.";
        cout << "\nNote that if the sequence is wrong, student may face issues in their marks";
        cout << "\nOnce you have reached the maximumm limit for answers, press 0\n";
        ofstream file("AnsKey.csv", ios::app);
        //teacher to make quiz here .
        string answer;
        //  cout << "check1";
        for (int j = 1; j <= 15; j++) {

            cout << "Enter Ans " << j << ": ";
            getline(cin, answer);
            file << answer << endl;
            if (answer == "0") {
                break;
            }
        }
        //  cout << "check2";
        QuestionMaker ques3;
        ques3.TimeSelection();

    }

    void TimeSelection() {

        for (int m = 0; m < 10; m++) {

            cout << "Teacher must select the time for student to attempt quiz\n";

            // Get the current system time
            auto currentTime = chrono::system_clock::now();

            // Convert the current time to a time point
            time_t currentTime_t = chrono::system_clock::to_time_t(currentTime);
        
            // Convert the time_t object to a string representation
            string timeString = ctime(&currentTime_t);

            // Print the current time
            cout << "Current time: " << timeString;

            //adding 1 hr to current time 
            // Add one hour to the current time
            auto futureTime = currentTime + chrono::hours(1);

            // Convert the future time to a time_t object
            time_t futureTime_t = chrono::system_clock::to_time_t(futureTime);

            // Convert the time_t object to a string representation
            timeafterhr = ctime(&futureTime_t);

            // Print the future time
            cout << "Time after 1 hour: " << timeafterhr;

            cout << "\n Time currently is " << timeString << " and the time after 1 hour will be " << timeafterhr << "\n";
            cout << "\n The Quiz will be ended after 1 hr at " << timeafterhr << "\n";
            cout << "Press 1 to proceed and to allow student to gave Quiz\n";
            cin >> quizallow;
            if (quizallow == 1) {
                //user alllowed to gave paper
                cout << "\nQuiz out";
                cout << "\nStudent allowed to perform Quiz until " << timeafterhr;

                break;
            }
            else {
                cout << "Error!!!! \n Quiz progress failed \n Recheck the time selection \n\n";
                //continue;
            }
        }


    }


};




















//teacher class functionalities starts 
class Teacher : public Profile {
protected:
    string teacname;
    string passteac;
  

public:
    void run() override {
        cout << "Running teacher profile...\n";

        // Login of teacher
        cout << "Teacher Name: ";
        cin >> teacname;
        cout << "Password: ";
        cin >> passteac;
        


        //teacher name check here 

        QuestionMaker questionmaker;

        if (1) {
            questionmaker.checkquiztype();

        }



    }
};









class CourseRegistration {

private:

    int studentId;
    int courseId;
    bool registered;
public:
    CourseRegistration(const std::string& filename) {
       // loadData(filename);
    }

    bool isRegistered(int studentId, int courseId) const {
     //   for (const auto& row : data) {
           // if (row.studentId == studentId && row.courseId == courseId) {
             //   return row.registered;
            }
       // }
       // return false; // Student or course not found
    



    };















class CSVFile {
private:
    string filename;
    ofstream file;

public:
    CSVFile(const string& filename) : filename(filename) {}

    bool open() {
        file.open(filename, ios::out | ios::trunc);
        return file.is_open();
    }

    void close() {
        file.close();
    }
};








int main() {
    int choice;
    unique_ptr<Profile> profile;
    

    while (true) {
        cout << "Select a profile:\n";
        cout << "1. Student\n";
        cout << "2. Teacher\n";
        cout << "0. Exit\n";
        cout << "\nEnter 5 if you want to clear all the files and cllose the cxv files\n";
        cout << "Note that it will terminate the program.\n";
        cout << "Enter your choice (1, 2, or 0): ";
        cin >> choice;

        if (choice == 1) {
            profile = make_unique<Student>();
           
        }
        else if (choice == 2) {
           
                profile = make_unique<Teacher>();
           
           
        }
        else  if (choice == 5) {
            CSVFile file1("AnsKey.csv");  
            CSVFile file2("MCQs.csv");
            CSVFile file3("StudentQuizAttempt.csv");


            if (file1.open() && file2.open() && file3.open()) {
                file1.close();
                file2.close();
                file3.close();
                cout << "CSV files cleared and closed." << endl;
            }
            else {
                cout << "Failed to open CSV files." << endl;
            }
        }

        else {
            cout << "Invalid choice. Please try again.\n";
            break;
        }



        profile->run();
    }
    return 0;
}




