#include <iostream>
#include <string>
using namespace std;

class Holiday
{
private:
   string name;
    int day;
    string month;
public:


    // Default constructor
    Holiday() : name(""), day(0), month("")
     {}
     

    // Constructor with parameters
    Holiday(string n, int d, string m) : name(n), day(d), month(m)
     {}

    // Getter methods
    string getName() const 
     {
         return name; 
     }
    int getDay() const 
     {
         return day;
     }
    string getMonth() const
     {
         return month; 
     }

    // Setter methods
    void setName(string n) 
    {
         name = n;
    }
    void setDay(int d)
     {
         day = d;
     }
    void setMonth(string m) 
    {
         month = m;
     }

    // display method
    void dispaly() const
     {
        cout << name << " on " << day << " " << month << endl;
    }

 
   /* Holiday(string n, int d, string m) : name(n), day(d), month(m) 
    {}*/


    //setter with conditions
    // Setter methods
    void set_name(string n)
     {
        if (n.length() <= 50) 
        {
            name = n;
        }
          else 
        {
            cout << "Error: name is too long. It should be 50 characters or less." << endl;
        }
    }
    void set_day(int d)
     {
        if (d >= 0)
         {
            day = d;
        } 
         else
         {
            cout << "Error: day cannot be negative." << endl;
        }
    }
    void set_month(string m) 
    {
        if (m.length() <= 10) 
        {
            month = m;
        } else 
        {
            cout << "Error: month is too long. It should be 10 characters or less." << endl;
        }
    }   

    bool inSameMonth(const Holiday& a, const Holiday& b)
     {
       return a.getMonth() == b.getMonth();
     }
};

//outside class functions
bool inSameMonth(const Holiday& a, const Holiday& b)
     {
       return a.getMonth() == b.getMonth();
     }

double avgDate(const Holiday arr[], int size)
 {
    double sum = 0.0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i].getDay();
    }
    return sum / size;
}     

int main() 
{
    // Create a Holiday object using the default constructor
    Holiday h1;
    cout << "Holiday 1: ";
    h1.dispaly();

    // Create a Holiday object using the parameterized constructor
    Holiday h2("New Year's Day", 1, "January");
    cout << "Holiday 2: ";
    h2.dispaly();

    // Use the setter methods with conditions to set the name, day, and month of h1
    h1.set_name("Independence Day");
    h1.set_day(4);
    h1.set_month("July");
    cout << "Holiday 1 (after setting name, day, and month): ";
    h1.dispaly();

    // Use the inSameMonth function to check if h1 and h2 are in the same month
    if (inSameMonth(h1, h2)) 
    {
        cout << h1.getName() << " and " << h2.getName() << " are in the same month." << endl;
    } else 
    {
        cout << h1.getName() << " and " << h2.getName() << " are not in the same month." << endl;
    }

    // Create an array of Holiday objects and calculate the average day
    const int SIZE = 3;
    Holiday arr[SIZE] = {h1, h2, Holiday("Labor Day", 5, "September")};
    double avgDay = avgDate(arr, SIZE);
    cout << "Average day of the holidays: " << avgDay << endl;

    return 0;
}
