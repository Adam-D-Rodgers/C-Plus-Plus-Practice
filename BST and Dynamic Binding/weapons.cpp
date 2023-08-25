//Adam Rodgers, 8/14/2023
//This file stores all the data and member functions for the weapons class
#include "product.h"
using namespace std;

//default constructor
weapon::weapon(): product(), damage_bonus(0) {}

//constructor with three arguments
weapon::weapon(const string source, string desc_source, int val, int dig, int damage): product(source, desc_source, val, dig), damage_bonus(damage){}

//Assignment operator overload
weapon & weapon::operator=(const weapon & source) {
	if(this == &source) return *this; 
	product::operator=(source);//calls base classes assignment operator and then sets the damage bonus
	damage_bonus = source.damage_bonus;
  return *this;
}

//display function
void weapon::display() const{
	cout << endl;
	product::display();
	cout << "weapon health bonus: " << damage_bonus << endl;
}

//Buy function
void weapon::buy(deque<shared_ptr<product>> & cart){
	cout << endl;
	cout << "You have bought the weapon!" << endl;
	cout << "It will slay your enemies on your journey!" << endl;
	shared_ptr<product> item = make_shared<weapon>(*this);//Makes a copy of this nodes info and put it in the cart. This makes it so when delete is called it doesnt have errors
	cart.push_back(item);
}

//Request an upgrade function
void weapon::request_upgrade(){
	cout << endl;
	cout << "The storkeeper says: \"I can make the damage bonus about 30% stronger, but it will be 40% more expensive\"" << endl;
	cout << "I will apply this to all items like this one" << endl;
	damage_bonus *= 1.3;
	price *= 1.4;
}

//Negotiate price, this changed the price of the item
void weapon::negotiate_price(){
	cout << endl;
	cout << "The storkeeper says: \"Since this is a weapon I will give you a 10% discount\"" << endl;
	price *= .9; 
}

//Menu function, This greatly increases efficency of the code, as instead of having 4 diffrent recursive loops in main for each
//buy, upgrade, and negotiate price it has a single loop that calls this function. 
void weapon::menu(deque<shared_ptr<product>> & cart){ 
	char x = 0;

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
					cout << "Please enter valid input" << endl;
					break; //No expection handling here as i want it to loop so the user can try to enter a valid input again
			}
	} while ((x != '0') && (x != '1'));
	
}

