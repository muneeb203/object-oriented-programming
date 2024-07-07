//============================================================================
// Name        : Q2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Person{
	string firstname;
	string secondname;

};
void concateateName(Person* person){
	string name=person->firstname+" "+person->secondname;
	cout<<name;
}


int main() {
	Person person;
	//Person* ptr;
//	ptr=&person;

	cout<<"\e[1mFirst name \e[0m";
	cin>>person.firstname;

	cout<<"\e[1mSecond name \e[0m";
	cin>>person.secondname;

	concateateName(&person);
	return 0;
}





