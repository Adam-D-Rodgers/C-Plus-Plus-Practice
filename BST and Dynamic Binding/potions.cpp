//Adam Rodgers, 8/14/2023
//This file stores all the data and member functions for the potions class
#include "product.h"
using namespace std;

//default constructor
potion::potion(): product(), effect("empty") {}

//constructor with three arguments
potion::potion(const string source, string desc_source, int val, int dig,  string buff): product(source, desc_source, val, dig), effect(buff){}

//Assignment operator overload
potion & potion::operator=(const potion & source) {
	if(this == &source) return *this; 
	product::operator=(source);//calls base classes assignment operator and then sets the buff
	effect = source.effect;
  return *this;
}

//display function
void potion::display() const{
	cout << endl;
	product::display();
	cout << "potion health bonus: " << effect << endl;
}

//Buy function
void potion::buy(deque<shared_ptr<product>> & cart){
	cout << endl;
	cout << "You have bought the potion!" << endl;
	cout << "It will help you on your journey!" << endl;
	shared_ptr<product> item = make_shared<potion>(*this);//Makes a copy of this nodes info and put it in the cart. This makes it so when delete is called it doesnt have errors
	cart.push_back(item);
}

//Request an upgrade function
void potion::request_upgrade(){
	cout << endl;
	cout << "The storkeeper says: \"Sorry I cant make them any stronger\"" << endl;
	cout << "The storkeeper says: \"A drop of a potion can turn into poison if taken in too high a concentration!\"" << endl;
	cout << "The storkeeper says: \"However you can buy them in bulk if you wish!\"" << endl;
}

//Negotiate price, this changed the price of the item
void potion::negotiate_price(){
	cout << endl;
	cout << "The storkeeper says: \"Since this is a potion I can give you a 50% discount\"" << endl;
	cout << "The storkeeper says: \"They are actually quite easy to make hahaha\"" << endl;
	price *= .5;
}

//Bulk buy function, takes user input and buy that many potions
void potion::bulk_buy(deque<shared_ptr<product>> & cart){
	cout << "The storkeeper says: \"How many would you like?\"" << endl;
	int amount = 0;
	cin >> amount;
	cin.ignore(100, '\n');
	cout << "The storkeeper says: \"Right away! I will give you " << amount << "\" of this type of potion" << endl;
	for(int i = 0; i < amount; ++i){
		shared_ptr<product> item = make_shared<potion>(*this);
		cart.push_back(item);
	}
}

//Menu function, This greatly increases efficency of the code, as instead of having 4 diffrent recursive loops in main for each
//buy, upgrade, and negotiate price it has a single loop that calls this function. 
void potion::menu(deque<shared_ptr<product>> & cart){ //Display menu function
	char x = 0;

	do{
			cout << endl;
			cout << "What would you like to do with this item?" << endl;
			display();
			cout << endl << endl;
			cout << "-1- Buy Item" << endl;//displays menu
			cout << "-2- Request For Item To Be Upgraded" << endl;
			cout << "-3- Haggle For Item" << endl;
			cout << "-4- Bulk Buy Item (TEST RTTI)" << endl;
			cout << "-0- Go Back" << endl;

			cin.clear();
			cin >> x;
			cin.ignore(100, '\n');

			switch(x){//calls needed function
				case '0':
					break;
				case '1':
					buy(cart);
					break;
				case '2':
					request_upgrade();
					break;
				case '3':
					negotiate_price();
					break;
				case '4':
					try {RTTI(cart);}
					catch(int ex){
						cout << "RTTI DIDNT WORK" << endl;
					}
					break;
				default:
					cout << "Please enter valid input" << endl;
					break; //No expection handling here as i want it to loop so the user can try to enter a valid input again
			}
	} while ((x != '0') && (x != '1') && (x != '4'));
}

//This function tests RTTI to make sure it works, spacifically called for RTTI
void potion::RTTI(deque<shared_ptr<product>> & cart){

	  shared_ptr<product> base = make_shared<potion>(*this);
	  shared_ptr<potion> test = std::dynamic_pointer_cast<potion>(base);
	  
      if(test){
        test->bulk_buy(cart);
      }
      else{
        throw 0;
      }
	  
}

