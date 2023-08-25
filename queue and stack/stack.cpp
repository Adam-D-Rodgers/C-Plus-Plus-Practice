//Adam Rodgers 
//This file is the .cpp file the the stack class

#include "stack.h"

//Defualt contructor
stack::stack(){
	head = nullptr;
	top = 0;
}

//Distructor
stack::~stack(){
	if(head){
		s_node * curr = head;	
		while(curr){
			delete [] curr->data;
			curr = curr->next;
		}
		while(head){
			s_node * temp = head->next;
			delete head;
			head = temp;
		}
	}
	head = nullptr;

};

//Push function
int stack::push(const road & input){

	if(top < 0) return 0;

	if(!head){
		head = new s_node;
		head->data = new road[MAX];
		head->data[0] = input;
		head->next = nullptr;
		++top;
	}
	else if(top < MAX){
		head->data[top] = input;
		++top;
	}
	else{
		top = 0;
		s_node * hold = head;
		head = new s_node; 
		head->data = new road[MAX];
		head->data[top] = input;
		head->next = hold;
		++top;
	}
	return 1;
}

//Pop function
int stack::pop(){
	if(!head) return 0;

	if(top == 0){
		s_node * hold = head->next;
		delete [] head->data;
		delete head;
		head = hold;
		top = MAX - 1;
	}
	else{
		--top;
	}
	return 1;
}

//Peek function
int stack::peek(road & input) const{
	if(!head) return 0;

	input = head->data[top - 1];

	return 1;
}


//Display function
int stack::displayW(){

	if(!head) return 0;	
	s_node * curr = head;

	for(int i = top - 1; i >= 0; --i){
		curr->data[i].display();
	}

	display(curr->next);
	return 1;
}

int stack::display(s_node *& head){
	if(!head) return 1;
	for(int i = MAX - 1; i >= 0; --i){
		head->data[i].display();
	}
	display(head->next);
	return 1;
}


