//Adam Rodgers, 
//This race class manages a race that genrates the terrain and simulates the race.


#pragma once
#include <string>
using std::string;
#include "contestent.h"

//Race class
class race {
	public:
		race();
		void sim_race();
		

	private:
			vector <robot> robots;
			list <rex> rexes;
			CLL toddlers;

			int finished_robots;
			int finished_rexes;
			
			void i_vectors(vector<robot>::iterator v); //iterate through vectors 
			void i_list(list<rex>::iterator i);
			array_LLL track;
};
