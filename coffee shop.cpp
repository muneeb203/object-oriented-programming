#include<iostream>
using namespace std;
class CoffeeShots {
public:
	string type;
	double price;
	float volume;
	char size;
	int s, m, i;



	CoffeeShots (double p, float v, string t = 0) {
		type = t;
		price = p;
		volume = v;
		

	}
	
	void setPrice(double p) {
		price = p;
	}
	double getPrice() {
		return price;
	}
	void setVolume(float v) {
		volume = v;
	}
	float getVolume() {
		return volume;
	}
	void setType(string typ) {
		type = typ;
	}
	string getType() {
		return type;
	}
	void setSize(char siz) {
		size=siz;
	}
	char getSize() {
		return size;
	}



	char sizecheck() {
		if((volume > 0) && (volume < 50)){
			size = s;
		
		}
		else if ((volume >= 50) && (volume < 75)) {
			size = m;

		}
		else if (volume >= 75) {
			size = i;
		}
		return size;
	}


	void upsize() {
		float vari;
		vari = volume + 5;
		if ((vari > 0) && (vari < 50)) {
			size = s;

		}
		else if ((vari >= 50) && (vari < 75)) {
			size = m;

		}
		else if (vari >= 75) {
			size = i;
		}
		cout << "The volume of coffee afer increasing 5ml is " << size << " catgery" << endl;

	}



};







//main func


int main() {
	CoffeeShots cf(45, 55,0);
	void setPrice();
	double getPrice();

	void setVolume();
	float getVolume();

	void setType();
	string getType();

	void setSize();
	char getSize();

	cout << "The origanl size is ";
	char sizehceck();


	void upsize();



	return 0;
}


