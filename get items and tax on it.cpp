
#include <iostream>
using namespace std;
class Scale{
private:
	double itemCost;
	double taxRate;

public:
Scale(){
	itemCost=0;
	taxRate=0;
}
Scale(double ic,double tr ){
	itemCost=ic;
	taxRate=tr;
}

// Getter and Setter for ic
  int getitem() {
      return itemCost;
  }

  void setX(int newitem) {
      itemCost = newitem;
  }

  // Getter and Setter for tr
    int getrate() {
        return taxRate;
    }

    void setrate(int newrate) {
        taxRate = newrate;
    }
    //tax return

    int getTax(){
    	double tax= taxRate*itemCost;
    	return tax;
    }

    int getTotal(){
    	double total=itemCost+getTax();
    	return total;
    }


};

int main(){


	Scale s(3,0.05);

	Scale s1(5,0.07);

	cout<<s.getitem()<<endl;

	cout<<s.getrate()<<endl;

	cout<<s.getTax()<<endl;

	cout<<s.getTotal()<<endl;

	cout<<s1.getitem()<<endl;

	cout<<s1.getrate()<<endl;

	cout<< s1.getTax()<<endl;

	cout<<s1.getTotal()<<endl;

}

