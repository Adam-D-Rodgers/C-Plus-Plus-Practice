//Adam Rodgers, 8/14/2023
//This file stores all the data and member functions for the armor class
#include "product.h"
using namespace std;

//default constructor
armor::armor(): product(), health_bonus(0) {}

//constructor with three arguments
armor::armor(const string source, string desc_source, int val, int dig, int health): product(source, desc_source, val, dig), health_bonus(health){}

//Assignment operator overload
armor & armor::operator=(const armor & source) {
	if(this == &source) return *this; 
	product::operator=(source); //calls base classes assignment operator and then sets the health bonus
	health_bonus = source.health_bonus;
  return *this;
}

//display function
void armor::display() const{
	cout << endl;
	product::display();
	cout << "armor health bonus: " << health_bonus << endl;
}

//Buy function
void armor::buy(deque<shared_ptr<product>> & cart){
	cout << endl;
	cout << "You have bought the piece of armor!" << endl;
	cout << "It will provide protection for you on your journey!" << endl;
	shared_ptr<product> item = make_shared<armor>(*this); //Makes a copy of this nodes info and put it in the cart. This makes it so when delete is called it doesnt have errors
	cart.push_back(item);
}

//Request an upgrade function
void armor::request_upgrade(){
	cout << endl;
	cout << "The storkeeper says: \"I can make the health bonus about 50% stronger, but it will be 50% more expensive\"" << endl;
	cout << "I will apply this to all items like this one" << endl;
	health_bonus *= 1.5;
	price *= 1.5; 
}

//Negotiate price, this changed the price of the item
void armor::negotiate_price(){
	cout << endl;
	cout << "The storkeeper says: \"Since this is a piece of armor I will give you a 20% discount\"" << endl;
	price *= .8;
}

//Menu function, This greatly increases efficency of the code, as instead of having 4 diffrent recursive loops in main for each
//buy, upgrade, and negotiate price it has a single loop that calls this function. 
void armor::menu(deque<shared_ptr<product>> & cart){ 
	char x = '0';

	do{
			cout << endl;
			cout << "What would you like to do with this item?" << endl;
			display();
			cout << endl << endl;
			cout << "-1- Buy Item" << endl; //displays menu
			cout << "-2- Request For Item To Be Upgraded" << endl;
			cout << "-3- Haggle For Item" << endl;
			cout << "-0- Go Back" << endl;

			
			cin >> x;
			cin.ignore(100, '\n');

			switch(x){ //calls needed function
				case '1':
					buy(cart);
					break;
				case '2':
					request_upgrade();
					break;
				case '3':
					negotiate_price();
					break;
				case '0':
					break;
				default:
					cout << endl << "PLEASE ENTER VALID INPUT" << endl;
					break; //No expection handling here as i want it to loop so the user can try to enter a valid input again
			}
	} while ((x != '0') && (x != '1'));
}

