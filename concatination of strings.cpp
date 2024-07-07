//============================================================================
// Name        : Qno7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class String
{

private:
		char *s;
		int size;

 public:
		String() : s(nullptr), size(0){


     }

			String(const char *str){
						size = strlen(str);
						s = new char[size+1];
						strcpy(s, str);
    }

			String(const String& other) : s(nullptr), size(0) {
					size = other.size;
					s = new char[size+1];
					strcpy(s, other.s);

    }



			~String(){

						delete[] s;
    }

				String operator+(const String& other) const {
						String result;
						result.size = size + other.size;
						result.s = new char[result.size+1];
						strcpy(result.s, s);
						strcat(result.s, other.s);
						return result;
    }

				char& operator[](int index) {

					return s[index];
				}



				const char& operator[](int index) const{

					return s[index];
				}



				friend ostream& operator<<(ostream& os, const String& str){

					os << str.s;
					return os;


				}

			};


int main()
 {
				String str1 = "hello";
				String str2 = "world";
				String str3 = str1 + str2;
				cout << str3 << endl;
				cout << str3[0] << endl;
				str3[0] = 'H';
				cout << str3 << endl;



					return 0;
			}

