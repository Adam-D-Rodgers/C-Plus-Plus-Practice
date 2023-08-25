//Adam Rodgers 
//This is the .cpp file for the finction of the class road
#include "road.h"
using namespace std;

//Defualt contructor
road::road(){
	name = nullptr;
	last_exit = nullptr;
	time = 0;
}

//Distructor
road::~road(){
	if(name){
		delete [] name;
	}
	name = nullptr;
	if(last_exit){
		delete [] last_exit;
	}
	last_exit = nullptr;
}

//Road copy constructor
road::road(const road & source){
	*this = source;
}

//Road copy assignment overload
road & road::operator=(const road & source){
	if(this == &source || !source.name || !source.last_exit) return *this;

	if(name){
		delete [] name;
		name = nullptr;
	}
	name = new char[strlen(source.name) + 1] {0};
	strncpy(name, source.name, strlen(source.name));

	if(last_exit){
		delete [] last_exit;
		last_exit = nullptr;
	}
	last_exit = new char[strlen(source.last_exit) + 1] {0};
	strncpy(last_exit, source.last_exit, strlen(source.last_exit));

	time = source.time;

	return *this;
};


//Display road
int road::display() const{
	cout << endl;
	cout << "Road: " << name << endl;
	cout << "Last Exit: " << last_exit << endl;
	cout << "Time: " << time << endl;
	return 1;
}

int road::set_name(const char * source){
	if(name) delete [] name;
	name = new char[strlen(source) + 1] {0};
	strncpy(name, source, strlen(source));

	return 1;
}

int road::set_last_exit(const char * source){
	if(last_exit) delete [] last_exit;
	last_exit = new char[strlen(source) + 1] {0};
	strncpy(last_exit, source, strlen(source));

	return 1;
}

int road::set_time(const int source){
	time = source;
	return 1;
}
