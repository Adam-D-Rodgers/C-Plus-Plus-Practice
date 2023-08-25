//Adam Rodgers, 
//This is one of the derived class of contestent. And one of the three racer classes. 
#include "contestent.h"
using namespace std;

//default constructor
robot::robot(): contestent( (char*) "ROBOT X" , (char*)"STREETS", (char*)"MOUNTAINS") {
}

//constructor with argumnets
robot::robot(char * a_name): contestent(a_name, (char*)"STREETS", (char*)"MOUNTAINS") {
}

//display function 
int robot::display() const {
	contestent::display();	
	return 1;
}

//randomly chooses an event to happen
void robot::events() {
	random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 7);
  int x = dis(gen);	

	cout << name << " gained 3 miles with steady progress" << endl;
	mile = mile + 3;


	switch(x){   //I will have a lot of diffrent event here to simulate diffrent things happening inside the race

		case 1:
			cout << name << " removed its limits and gained 3 miles!!" << endl;
			mile = mile + 3;
			break;
		
		case 2:
			cout << name << " broke down and lost 2 miles!!" << endl;
			mile = mile - 2;
			break;

		case 3:
			cout << name << " turned on cruise control...so nothing changed..." << endl;
			break;

		case 4:
			cout << name << " turned on jet boosters!! gained 5 miles!" << endl;
			mile += 5;
			break;

		case 5: 
			cout << name << " turned on all terrain mode! but that didnt change much..." << endl;
			break;

		case 6:
			cout << name << " got the wrong fuel!! lost 3 miles!" << endl;
			mile -= 3;
			break;

		case 7: 
			cout << name << " got inspired by the terminator!! oh no! gained 9 miles!!!!" << endl;
			mile += 9;
			break;
	}

	if(mile < 0) mile = 0;
	if(mile > 100) mile = 100;

	cout << name << " IS CURRENTLY AT MILE: " << mile << endl << endl;
}

//checks if contestent wins
int robot::check_win(int robots_finished) {
	if(mile >= 100){
		cout << endl << endl << name << " HAS FINISHED THE RACE AND TAKEN PLACE NUMBER ";
		cout << robots_finished  + 1 << " IN THE ROBOT RACE!" << endl << endl;
		return 1;
	}

	return 0;
}

//implements the terrain effect
void robot::terrain_effect(const array_LLL * track){
	int spot = 0;
	if(mile < 20){
		spot = 0;
	} 
	else if (mile <=20 && mile < 40){
		spot = 1;
	}
	else if (mile <=40 && mile < 60){
		spot = 2;
	}
	else if (mile <=60 && mile < 80){
		spot = 3;
	}
	else if (mile <=80){
		spot = 4;
	}

	int effect = track->check_track(t_plus, t_minus, spot);
	if (effect == 1)
	{
		cout << "THE TERRAIN IS FAVORABLE TO " << name << "  THEY WILL EASILY GAIN MILES, +3 MILES" << endl;
		mile += 3;
	} 
	else if(effect == 2){
		cout << "THE TERRAIN IS DISADVANTAGES TO " << name << " THEY WILL STRUGGLE TO GAIN MILES, -3 MILES" << endl;
		mile -= 3;
	}
}
