//ADAM RODGERS, 10/18/2022
//  This program is an ADT made to create a linked list of arrays
//  in order to allow the user to plan a trip for maximum safety
//  The program is split into 3 main parts, the stack, the queue, and the road


//  This program is the queue. It allows the user to enqueue a road segment
//  that they wish to travel. And then dequeue it when the road segment has
//  been traveled. This allows easy and efficent path planning.

//This program will have 4 functions
//Enqueue: Enqueue a Road-Segment to the Rear
//Dequeue: Dequeue as the motorcade travels from Front
//Peek   : Peek from the Queue (to allow the client to get security to the next 
//         location ahead of time)
//Display: Display the Queue

//  Return types will be of 1(success) or 0(failure) any other type will be
//  explained above function decleration in comments
#include "road.h"

struct q_node{
	road data;
	q_node * next;
};

class queue{

	public:
		queue();
		~queue();
		
		int display() const;
		int enqueue(const road & input);
		int dequeue(road & output);
		int peek(road & input) const;


	private:
		q_node * rear;
};
