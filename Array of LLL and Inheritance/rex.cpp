//Adam Rodgers, 
//This is one of the derived class of contestent. And one of the three racer classes. 
#include "contestent.h"
using namespace std;

//default constructor
rex::rex(): contestent( (char*) "rex X" , (char*)"PLAINS", (char*)"TUNNELS") {
}

//constructor with argumnets
rex::rex(char * a_name): contestent(a_name, (char*)"PLAINS", (char*)"TUNNELS") {
}

//display function 
int rex::display() const {
	contestent::display();	
	return 1;
}

//randomly chooses an event to happen
void rex::events() {
	random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 7);
  int x = dis(gen);	

	cout << name << " gained 2 miles with steady progress" << endl;
	mile = mile + 2;


	switch(x){   //I will have a lot of diffrent event here to simulate diffrent things happening inside the race

		case 1:
			cout << name << " chased after some delicious looking prey on the track! gained 4 miles!" << endl;
			mile = mile + 4;
			break;
		
		case 2:
			cout << name << " got really hungry! lost 3 miles!" << endl;
			mile = mile - 3;
			break;

		case 3:
			cout << name << " crashed through the track and found a shortcut! gained 5 miles!!" << endl;
			mile += 5;
			break;

		case 4:
			cout << name << " was enraged and started charging ahead! gained 3 miles!!" << endl;
			mile += 3;
			break;

		case 5: 
			cout << name << " got caught in a trap!! lost 4 miles!" << endl;
			mile -= 4;
			break;
		
		case 6:
			cout << name << " stopped and smelled the roses?!? nothing really changed..." << endl;
			break;
		case 7: 
			cout << name << " got distracted by its tiny arms? nothing really changed" << endl;
			break;
	}

	if(mile < 0) mile = 0;
	if(mile > 100) mile = 100;

	cout << name << " IS CURRENTLY AT MILE: " << mile << endl << endl;
}

//checks if contestent wins
int rex::check_win(int rexs_finished) {
	if(mile >= 100){
		cout << endl << endl << name << " HAS FINISHED THE RACE AND TAKEN PLACE NUMBER ";
		cout << rexs_finished  + 1 << " IN THE REX RACE!" << endl << endl;
		return 1;
	}

	return 0;
}


//implements the terrain effect
void rex::terrain_effect(const array_LLL * track){
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