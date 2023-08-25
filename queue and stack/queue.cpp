//Adam Rodgers 
//This is the .cpp file for the function queue.h
#include "queue.h"
using namespace std;

//Defualt contructor
queue::queue(){
	rear = nullptr;
}

//Defualt contructor
queue::~queue(){
	if(!rear){
		return;
	}	
	else{
		if(rear->next == rear){
			delete rear;
			rear = nullptr;
		}	
		else{
			q_node * curr = rear->next;
			do{
				q_node * temp = curr->next;
				delete curr;
				curr = temp;

			} while (curr != rear->next);
		}
	}

}

//Enqueue function
int queue::enqueue(const road & input){
	if(!rear){
		rear = new q_node;
		rear->data = input;
		rear->next = rear;
	}
	else{
		q_node * hold = rear->next;
		rear->next = new q_node;
		rear->next->data = input;
		rear = rear->next;
		rear->next = hold;
	}
	return 1;
}

//Dequeue function
int queue::dequeue(road & output){
	if(!rear) return 0;
	if(rear->next == rear){
		output = rear->data;
		delete rear;
		rear = nullptr;
	}
	else{
		output = rear->next->data;
		q_node * hold = rear->next;
		rear->next = hold->next;
		delete hold;
	}
	return 1;
}

//Peek function
int queue::peek(road & input) const{
	if(!rear) return 0;

	input = rear->next->data;
	return 1;
}

//Display function
int queue::display() const{
	if(!rear) return 0;
	if(rear->next == rear){
		rear->data.display();
	}	
	else{
		q_node * curr = rear->next;

		do{
			curr->data.display();
			curr = curr->next;

		} while (curr != rear->next);
	}
	return 1;
}
