//Adam Rodgers 
//This is the client code for the stack and queue ADT's
#include "stack.h"
#include "queue.h"
using namespace std;

int make(road & test);
char menu();
int main() {

	stack test;
	queue que;
	road input;
	char option = 0;

	while((option = menu()) != '0'){
		if(option == '1'){
			cout << "Option 1" << endl;	
			make(input);
			test.push(input);	
		}
		else if(option == '2'){
			cout << "Option 2" << endl;
			test.pop();
		}
		else if(option == '3'){
			cout << "Option 3" << endl;
			road source;
			test.peek(source);		
			
		}
		else if(option == '4'){
			cout << "Option 4" << endl;
			test.displayW();
		}
		else if(option == '5'){
			cout << "Option 5" << endl;
			make(input);
			que.enqueue(input);
		}
		else if(option == '6'){
			cout << "Option 6" << endl;
			road output;
			que.dequeue(output);
			test.push(output);
		}
		else if(option == '7'){
			cout << "Option 7" << endl;
			road source;
			que.peek(source);
		}
		else if(option == '8'){
			cout << "Option 8" << endl;
			que.display();
		}
		else {
			cout << "Please enter valid option" << endl;
		}	
	} 
	
	return 0;		
}

int make(road & test){
	road new_road;
	char * name = new char[101]{0};
	char * last_exit = new char[101]{0};
	int time = 0;

	cout << "Please Enter Road Name" << endl;
	cin.getline(name, 100);
	new_road.set_name(name);
	
	cout << "Please Enter Last Exit" << endl;
	cin.getline(last_exit, 100);
	new_road.set_last_exit(last_exit);

	cout << "Please Enter Time In Minutes" << endl;
	cin >> time;
	cin.ignore(100, '\n');
	new_road.set_time(time);
	test = new_road;
	cout << endl << "Node Entered: " << endl;
	new_road.display();

	delete [] name;	
	delete [] last_exit;
	return 1;		
}

char menu(){
	cout << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "Please enter option number you wish to use: " << endl;
	cout << endl;
	cout << "	-1- Push node in stack" << endl;
	cout << "	-2- Pop node in stack" << endl;
	cout << "	-3- Peek first node in stack" << endl;
	cout << "	-4- Display all nodes in stack" << endl;
	cout << endl;
	cout << "	-5- Enqueue node in queue" << endl;
	cout << "	-6- Dequeue node in queue" << endl;
	cout << "	-7- Peek first node in queue" << endl;
	cout << "	-8- Display all nodes in queue" << endl;
	cout << "	-0- Exit program" << endl;
	cout << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << endl;
	char temp = 0;
	cin >> temp;
	cin.ignore(100, '\n');
	return temp;

}
