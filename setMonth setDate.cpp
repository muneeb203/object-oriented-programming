
#include <iostream>
#include <string>

using namespace std;

class Date 
{
private:
    int year;
    int month;
    int day;

  public:
    Date() 
    {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) 
    {
        year = y;
        month = m;
        day = d;
    }

    void setday(int d) 
    {
        day = d;
    }

    int getday()
     {
        return day;
    }

    void setmonth(int m)
     {
        month = m;
    }

    int getmonth()
     {
        return month;
    }

    void setyear(int y)
     {
        year = y;
    }

    int getyear() 
    {
        return year;
    }

 void addD(int days)
  {
  int monthDays;
    switch (month)
     {
    case 2:
     if (isLeapYear(year))
      monthDays = 29;
     else
   monthDays = 28;
   break;
   case 4:
   case 6:
   case 9:
   case 11:
   monthDays = 30;
     break;
  default:
    monthDays = 31;
}
 day += days;
 while (day > monthDays) 
 {
   day -= monthDays;
   month++;
   if (month > 12) 
   {
       month = 1;
       year++;
 }

    switch (month) 
    {
     case 2:
      if (isLeapYear(year))
         monthDays = 29;
      else
          monthDays = 28;
     break;
 
     case 11:
     monthDays = 30;
     break;
     default:
      monthDays = 31;
            }
        }
    }

void addmD(int m, int d)
 {
 month += m;
 if (month > 12) {
   year += month / 12;
    month = month % 12;
        }
  addD(d);
    }

void addweeks(int weeks)
 {
  addD(weeks * 7);
 }

void subtractM(int days) 
{
   int monthDays;
    switch (month) {
   case 2:
   if (isLeapYear(year))
   monthDays = 29;
    else
       monthDays = 28;
    break;
  
    case 11:
   monthDays = 30;
    break;
     default:
    monthDays = 31;
 }
  day -= days;
  while (day <= 0)
   {
   month--;
     if (month <= 0)
      {
      month = 12;
      year--;
  }
  switch (month) 
  {
   case 2:
   if (isLeapYear(year))
  monthDays = 29;
   else
    monthDays = 28;
      break;
  
   case 11:
    monthDays = 30;
    break;
   default:
     monthDays = 31;
            }
  day += monthDays;
        }
    }

 void subtractMD(int m, int d) 
 {
        subtractM(m * 30 + d);
    }

 string toString()
  {
        return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
    }



    bool isLeapYear(int year)
     {
        if (year % 4 != 0)
            return false;
        else if (year % 100 != 0)
            return true;
        else if (year % 400 != 0)
            return false;
        else
            return true;
    }
};

int main() {
    Date d(2003, 12, 31);
    cout << d.toString() << endl;

    d.addmD(1, 29);
    cout << d.toString() << endl;

    d.subtractMD(1, 29);
    cout << d.toString() << endl;

    d.addweeks(2);
    cout << d.toString() << endl;

    return 0;
}

