//============================================================================
// Name        : Qno2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;
class Player{
private:
	string username;
	int player_level, won, lost;
	string hero_name;
public:

	void Login () {
		cout<<"Enter the username of the player";
		cin>>username;
		cout<<"Enter the player level ";
		cin>>player_level;
	}

	void Record () {
		cout<<"Win loss of player is as follows ";
		cout<<"No of won ";
		cin>>won;
		cout<<"No of matches lost";
		cin>>lost;
	}

	void select_hero (int hero_no){
		cout<<"Select the following hero from following available options ";
		cout<<"Lion\nTiger\nAshau\nLoish\nAkisj\nkasj\naijs\nkasj\n";
		cin>>hero_no;
		if (hero_no==1){
			cout<<"Selected Hero is Lion";
		}
		else if (hero_no==2){
			cout<<"Selected hero is Ashau";
		}

		else if (hero_no==3){
					cout<<"Selected hero is Loish";
				}
		else if (hero_no==4){
					cout<<"Selected hero is Akisj";
				}
		else if (hero_no==5){
					cout<<"Selected hero is kasj";
				}
		else {
			cout<<"Wrong Input";
		}
	}


void update_performance(int is_victory ){
	cout<<"\nWhat was the player outcome in last battle \n";
	cout<<"1.Won\n";
	cout<<"2.Loss\n";
	cin>>is_victory;
	if (is_victory==1){
		won++;
	}
	else if (is_victory==2){
		lost++;
	}
	else{
		cout<<"Wrong output!!!!!!!!!\n";
	}
	cout<<"Won battles are "<<won<<" and lost battles are "<<lost << " ."<<endl;
}


};



class PlayerManagementSystem{




};














int main(){

Player p;
p.Login();
p.Record();
p.select_hero(5);
p.update_performance(2);
}
