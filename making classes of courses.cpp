#include <iostream>
#include <string>

using namespace std;

class Instructor {
private:
    string lastName;
    string firstName;
    string officeNumber;
public:
    Instructor() : lastName(""), firstName(""), officeNumber("") {}
    Instructor(string ln, string fn, string on) : lastName(ln), firstName(fn), officeNumber(on) {}
    void setInstructor(string ln, string fn, string on) {
        lastName = ln;
        firstName = fn;
        officeNumber = on;
    }
    void printInstructor() const {
        cout << "Instructor: " << lastName << ", " << firstName << ", Office: " << officeNumber << endl;
    }
};

class TextBook {
private:
    string title;
    string author;
    string publisher;
public:
    TextBook() : title(""), author(""), publisher("") {}
    TextBook(string t, string a, string p) : title(t), author(a), publisher(p) {}
    void setTextBook(string t, string a, string p) {
        title = t;
        author = a;
        publisher = p;
    }
    void printTextBook() const {
        cout << "Textbook: " << title << ", Author: " << author << ", Publisher: " << publisher << endl;
    }
};

class Course {
private:
    string courseName;
    Instructor instructor;
    TextBook textbook;
public:
    Course(string cn, Instructor i, TextBook t) : courseName(cn), instructor(i), textbook(t) {}
    void printCourse() const {
        cout << "Course: " << courseName << endl;
        instructor.printInstructor();
        textbook.printTextBook();
    }
};

int main() {
    Instructor myInstructor("Laraib", "Afzal", "233");
    TextBook myTextBook("Introduction to OOP", "Muneeb Qureshi", "ABC Publishing");
    Course myCourse("oop", myInstructor, myTextBook);
    myCourse.printCourse();

    return 0;
}