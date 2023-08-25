//Adam Rodgers, 
//This is one of the derived class of contestent. And one of the three racer classes. 
#include "contestent.h"
using namespace std;

//default constructor
toddler::toddler(): contestent( (char*) "toddler X" , (char*)"DREAMLAND", (char*)"ALL OTHERS"), last_name(nullptr) {
}

//constructor with argumnets
toddler::toddler(char * a_name, char * source): contestent(a_name, (char*)"DREAMLAND", (char*)"ALL OTHERS"), last_name(nullptr) {
	if(last_name) delete [] last_name;
  last_name = new char[strlen(source) + 1] {0};
  strncpy(last_name, source, strlen(source));
}

//copy constructor
toddler::toddler(const toddler & source){
	*this = source;
}

//desructor
toddler::~toddler(){
	if(last_name){
		delete [] last_name;
	}
	last_name = nullptr;
}

//assignmnet operator
toddler & toddler::operator=(const toddler & source){
	if(this == &source) return *this;
	contestent::operator=(source);

	if(source.last_name){
		if(last_name){
      delete last_name;
      last_name = nullptr;
    }
    last_name = new char[strlen(source.last_name) + 1] {0};
    strncpy(last_name, source.last_name, strlen(source.last_name));
	} else {
		last_name = nullptr;
	}			
  return *this;

}

//display function 
int toddler::display() const {
	contestent::display();	
	return 1;
}

//randomly chooses an event to happen
void toddler::events() {
	if(strcmp(name, (char *)"finished") == 0) return;

	random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 7);
  int x = dis(gen);	

	cout << name << " " <<  last_name << " gained 1 mile with steady progress" << endl;
	mile = mile + 1;


	switch(x){   //I will have a lot of diffrent event here to simulate diffrent things happening inside the race

		case 1:
			cout << name << " " << last_name << " asked for help! feeling sorry their parents drove them in the car for 8 miles!" << endl;
			mile = mile + 8;
			break;
		
		case 2:
			cout << name << " " << last_name << " forgot about the race for a bit and lost 4 miles!" << endl;
			mile = mile - 4;
			break;

		case 3:
			cout << name << " " << last_name << " was picked up by a drone and was dropped off 9 miles ahead?!" << endl;
			mile = mile + 9;
			break;
		case 4:
			cout << name << " " << last_name << " got picked up by a stork and dropped off 6 miles ahead!" << endl; 
			mile += 6;
			break;
		case 5:
			cout << name << " " << last_name << " took a nap!? lost 5 miles?!" << endl;
			mile -= 5;
			break;
		case 6: 
			cout << name << " " << last_name << " crawled forward very slowly nothing really changed..." << endl;
			break;
		case 7:
			cout << name << " " << last_name << " stopped for a snack but nothing really changed..." << endl;
			break;
	}

	if(mile < 0) mile = 0;
	if(mile > 100) mile = 100;

	cout << name << " " << last_name << " IS CURRENTLY AT MILE: " << mile << endl << endl;
}

//checks if contestent wins
int toddler::check_win(int toddlers_finished) {
	
	if(strcmp(name, (char *)"finished") == 0) return 0;

	if(mile >= 100){
		cout << endl << endl << name  << " " << last_name << " HAS FINISHED THE RACE!!";
		cout << "AND TAKEN PLACE NUMBER " << toddlers_finished + 1 << "!!" << endl << endl;
		
		strcpy(name, (char *)"finished");
		return 1;
	}

	return 0;
}

//implements the terrain effect
void toddler::terrain_effect(const array_LLL * track){
	if(strcmp(name, (char *)"finished") == 0) return;
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
	else {
		cout << "THE TERRAIN IS DISADVANTAGES TO " << name << " THEY WILL STRUGGLE TO GAIN MILES, -2 MILES" << endl;
		mile -= 1;
	}
}
