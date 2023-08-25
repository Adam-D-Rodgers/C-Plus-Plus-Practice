//Adam Rodgers, 
//This is the base class for all the contestents. All the racer classes are derived from this class. 
#include "contestent.h"
using namespace std;

//default constructor
contestent::contestent(): name(nullptr), mile(0), t_plus(nullptr), 
			t_minus(nullptr) {
}

//constructor with three arguments
contestent::contestent(const char * source, char * terrain_p, char * terrain_m): name(nullptr), mile(0), t_plus(nullptr), 
	                t_minus(nullptr) {
                                
	if(name) delete [] name;
        name = new char[strlen(source) + 1] {0};
        strncpy(name, source, strlen(source));

        if(t_plus) delete [] t_plus;
        t_plus = new char[strlen(terrain_p) + 1] {0};
        strncpy(t_plus, terrain_p, strlen(terrain_p));

	if(t_minus) delete [] t_minus;
        t_minus = new char[strlen(terrain_p) + 1] {0};
        strncpy(t_minus, terrain_m, strlen(terrain_m));
}

//destructor
contestent::~contestent() {
	if(name){
		delete [] name;
	}
	name = nullptr;
	
 	if(t_plus){
                delete [] t_plus;
        }
        t_plus = nullptr;

	if(t_minus){
                delete [] t_minus;
        }
        t_minus = nullptr;
}

//copy constructor
contestent::contestent(const contestent & source){
	*this = source;
}

//assignment operator
contestent & contestent::operator=(const contestent & source) {
	
	if(this == &source || !source.name || !source.t_plus) return *this;

        if(name){
                delete [] name;
                name = nullptr;
        }
        name = new char[strlen(source.name) + 1] {0};
        strncpy(name, source.name, strlen(source.name));

        if(t_plus){
                delete [] t_plus;
                t_plus = nullptr;
        }
        t_plus = new char[strlen(source.t_plus) + 1] {0};
        strncpy(t_plus, source.t_plus, strlen(source.t_plus));

	if(t_minus){
                delete [] t_minus;
                t_minus = nullptr;
        }
        t_minus = new char[strlen(source.t_minus) + 1] {0};
        strncpy(t_minus, source.t_minus, strlen(source.t_minus));

        return *this;

}

//display function
int contestent::display() const{
	cout << endl;
	cout << name << " is currently at mile " << mile << endl;
	cout << "Remember " << name << " is good on " << t_plus;
	cout << " and bad on " << t_minus << endl << endl;

	return 1;
}



