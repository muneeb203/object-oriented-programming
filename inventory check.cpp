//============================================================================
// Name        : Qno2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Product
{
private:
		int quantity;
		static int objCount;
		int serialNo;

public:
		int getQuantity() const {

			return quantity;


		}

  int getSerialNo() const{

	  return serialNo;

  }



  static int getObjCount() {

	  return objCount;

  }

  	  Product (int totalQuantityOfProduct,int serialNumberOfProduct ){
			quantity=totalQuantityOfProduct;
			serialNo=serialNumberOfProduct;
  	  }



  	  void operator-(int quantity) {
  		  this->quantity = -quantity;
     }


};


int Product:: objCount=0;



int main() {

  Product c1(10, 1);
  Product c2(20, 2);
  Product c3(30, 3);

	  cout << "Total number of objects: " << Product::getObjCount() << endl;

	  cout << "Quantity of c1: " << c1.getQuantity() << endl;

	  cout << "Serial number of c1: " << c1.getSerialNo() << endl;

	  c1 - 5;



	  cout << "Product 1 quantity after subtraction: " << c1.getQuantity() << endl;



  	  	  return 0;


}

