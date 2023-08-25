//ADAM RODGERS, 10/18/2022
//This program is an ADT made to create a linked list of arrays
//In order to allow the user to plan a trip for maximum safety
//The program is split into 3 main parts, the stack, the queue, and the road

//This program file is the road, it is made to store the low level data of
//each road segment throughout the trip
#pragma once
#include <iostream>
#include <cctype>
#include <cstring>

class road{

	public:
		road();
		~road();
		road(const road & source);
		road& operator=(const road & source);
	
		int display() const;
		int set_name(const char * source);
		int set_last_exit(const char * source);
		int set_time(const int source);

	private:
		char * name;
		char * last_exit;
		float time; 
};

