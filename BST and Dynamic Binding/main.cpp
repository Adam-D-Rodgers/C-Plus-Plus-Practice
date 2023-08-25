//Adam Rodgers, 8/14/2023
//This assignment simulates a stores that the user can buy three diffent types of items in. 
//For my store I went with a RPG theme in continuation of my last assignment.
//The three items that the user can buy are: Armor, Weapons, and Potions. 
//Each has its own unique data member to diffrentiate them. 
//This program uses dynamic binding with a self similer interface across all three types of items.
#include <iostream>
#include "product.h"
#include "tree.h"
using namespace std;
//Menu function to make the code cleaner
char menu();

//Main function of the program
//Its main jobs are to call the menu function and then based on the user input run the required function or code. 
int main(){
	char input = '9'; //All my data members in main
	deque<shared_ptr<product>> cart;
	int temp;
	tree shop;
	deque<shared_ptr<product>>::iterator it;
	string search;

	
	shop.make_store(); 
	shop.displayW();

	//Main while loop and menu
	while((input = menu()) != '0'){ //Main loop of the program, calls menu 
		switch(input){
			case '1':
				cout << "What product would you like to look at? PLEASE ENTER PRODUCT CODE: ";
				cin >> temp;
				shop.purchaseW(temp, cart);
				break;
			case '2':
				cout << endl;
  			for (it = cart.begin(); it != cart.end(); ++it){ //Iterates through the STL deque
     			(*it)->display();
				}
  			cout << endl;
				break;
			case '3':
				shop.displayW();
				break;
			case '4':
				cout << "What product would you like to remove? PLEASE ENTER PRODUCT NAME: ";
				getline(cin, search);
				//cin.ignore('\n');
				shop.removeW(search);
				break;
			case '5':
				shop.remove_all();
				break;
			default:
				cout << "Please enter valid input" << endl;
				cin.clear();
				break; //No expection handling here as i want it to loop so the user can try to enter a valid input again
		}
	}

	return 0;
}


//Menu function to make code cleaner
char menu(){

	cout << endl << endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "Please enter option number you wish to use: " << endl;
	cout << endl;
	cout << "       -1- Look At Item" << endl;
	cout << "       -2- Check Shopping cart" << endl;
	cout << "       -3- Display available items" << endl;
	cout << "       -4- Test Remove Item" << endl;
	cout << "       -5- Test Remove ALL" << endl;
	cout << "       -0- Exit program" << endl;
	cout << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

	char temp = 0;
	cin >> temp;
	cin.ignore(100, '\n');
	return temp;
}



