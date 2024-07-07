//============================================================================
// Name        : Qno1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
class Distance{

private:
	int feet;
    int inches;

public:
    Distance(int f=0,int i=0){
        feet = f + i/12;
        inches = i % 12;

    }

    // Get & set func for feet
    void set_Feet(int f){
        feet = f;
    }

    int get_Feet() const {
        return feet;
    }

    // Get & set func for inches
    void set_Inches(int i){
        feet += i/12;
        inches = i % 12;
    }

    int get_Inches() const{
        return inches;
    }

    Distance operator+(const Distance& d) {
        int f = feet + d.feet;
        int i = inches + d.inches;
        return Distance(f,i);
    }

    Distance operator-(const Distance& d) {
        int f = feet - d.feet;
        int i = inches - d.inches;
        if (i < 0) {
            i += 12;
            f--;
        }
        return Distance(f, i);
    }
};

int main() {
    Distance dis1 (1, 2);
    Distance dis2 (3, 4);
    Distance dis3 = dis1 + dis2;
    Distance dis4 = dis1 - dis2;


    //printing data
    cout << "d1= " << dis1.get_Feet() << "feet, " << dis1.get_Inches() << "inches" << endl;
    cout << "d2= " << dis2.get_Feet() << "feet, " << dis2.get_Inches() << "inches" << endl;
    cout << "d1+d2= " << dis3.get_Feet() << "feet, " << dis3.get_Inches() << "inches" << endl;
    cout << "d1-d2= " << dis4.get_Feet() << "feet, " << dis4.get_Inches() << "inches" << endl;

    return 0;
}
