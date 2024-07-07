//============================================================================
// Name        : q1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
struct information{
	string name;
	float age;
	string adress;

};


int main() {
	information s1;
	information s2;
	string check;


	//person 1
	cout<<"Enter name of first person ";
	cin>>s1.name;

	cout<<"Enter age of "<<s1.name;
	cin>>s1.age;

	cout<<"Enter adress of "<<s1.name;
	cin>>s1.adress;

	//person 2

	cout<<"Enter name of second person";
	cin>>s2.name;

	cout<<"Enter age of "<<s2.name;
	cin>>s2.age;

	cout<<"Enter adress of "<<s2.name;
	cin>>s2.adress;

	cout<<endl;

	cout<<"Enter name of 3rd person ";
	cin>>check;

	cout<<endl;

	if(check==s1.name){
		cout<<"Match found "<<endl;
		cout<<"Name is "<<s1.name<<endl;
		cout<<"Age is "<<s1.age<<endl;
		cout<<"Adress is "<<s1.adress<<endl;

	}
	else if(check==s2.name){
		cout<<"Match found "<<endl;
		cout<<"Name is "<<s2.name<<endl;
		cout<<"Age is "<<s2.age<<endl;
		cout<<"Adress is "<<s2.adress<<endl;

	}
	else{
		cout<<"No match found"<<endl;
	}

}


