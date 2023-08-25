//ADAM RODGERS, 10/18/2022
//This program is an ADT made to create a linked list of arrays
//In order to allow the user to plan a trip for maximum safety
//The program is split into 3 main parts, the stack, the queue, and the road

//This program is the stack, it allows the user to input one at a time and
//pop one at a time from the top.
//With this function the user can add a road segment one by one
//and in case of emergincy, retrack each one of their steps.


//The program will have a 4 functions
//Push: Push a Road-Segment at the top 
//Pop:Pop the most recent from the Top 
//Peek:Peek the most recent at the Top of stack 
//Display:Display the entire journey taken so far 

//Return types will be of 1(success) or 0(failure) any other type will be
//explained above function decleration in comments


#include "road.h"

struct s_node{
	road * data;
	s_node * next;
};

const int MAX = 3;//max array length

class stack{

	public:
		stack();
		~stack();

		int displayW();
		int display(s_node *& head);
		int push(const road & input);
		int peek(road & input) const;
		int pop();

	private:
		s_node * head;
		int top;
};
