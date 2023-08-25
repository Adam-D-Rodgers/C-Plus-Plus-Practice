//Adam Rodgers, 
//This program simulates 3 diffrent races. With three diffrent types of contestents.
//Each having there own terrain effects and events that happen mid race.

//terrain effects
// robots: +streets -mountains
// toddlers: +dreamland -all_others
// T-rexes: +plains -tunnels

#include <iostream>
#include "contestent.h"
#include "race.h"
using namespace std;

 //main function
int main(){

	race vec_test;
	vec_test.sim_race();

	// TEST CODE
	/*toddler test((char*)("TODDLER JACK JACK"), (char *)"WILLOW");
	test.display();


	cout << endl << "ARGUMENT constructor TEST" << endl;
	toddler testB((char*)("TODDLER MATILDA"), (char *)"QUATAMA");
	testB.display();


	cout << endl << "COPY TEST" << endl;
	testB = test;
	testB.display();

	cout << endl << "COPY constructor TEST" << endl;
	toddler testC(testB);
	testC.display();	

	array_LLL LLLtest;
	LLLtest.make_array();
	LLLtest.displayW();

	*/

	return 0;
}
