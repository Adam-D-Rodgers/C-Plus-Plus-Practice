//Adam Rodgers, 8/14/2023
//This file stores all the .h data for all the other classes but not the tree class and node class
//This file stores all the prototypes of the functions used for product, armor, weapon, and potion objects.
#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib> 
#include <ctime>
#include <random>
#include <deque>
#include <memory>
using std::deque;
using std::string;
using std::istream;
using std::ostream;
using std::shared_ptr;
using std::make_shared;


//product class
class product {
	public:
		product(): name("none"), desc("none"), price(0), code(0){} //default constructor
		product(const string source, string description, int val, int dig): name(source), desc(description), price(val), code(dig){} // constructor with arguments
		product(const product & source){*this = source;} //Copy contructor
		product& operator =(const product & source){ //Assignment operator overload
			if(this == &source) return *this; //No exception handling here since I think we woudlnt want to just give an error rather have the program still work
			name = source.name;
			desc = source.desc;
			price = source.price;
			code = source.code;
			return *this;
		}
		//virtual ~product(){};

		//these are the 5 vertual function of this assignment
		virtual void buy(deque<shared_ptr<product>> &) = 0; //Buy the prodcut with the shoping cart as argument
		virtual void request_upgrade() = 0; //Upgrades all items of that type
		virtual void negotiate_price() = 0; //Negotiates the price of item
		virtual void menu(deque<shared_ptr<product>> & cart) = 0; //Menu hub to increase effeciency of the code
		
		virtual void display() const{ //Display function
			std::cout << std::endl;
			std::cout << "Product name: " << name << std::endl;
			std::cout << "Product discription: " << desc << std::endl;
			std::cout << "Product price: " << price << std::endl;
			std::cout << "Product code: " << code << std::endl;
		} 

		string get_name(){ //Get name function
			return name;
		}

		int get_code(){ //Get code function
			return code;
		}

		

	protected:
		string name;
		string desc;
		int price;
		int code;
};

//armorclass
class armor: public product{

	public:
		armor();//default constructor
		armor(const string source, string description, int cost, int dig, int health); //constructor with arguments
		armor(const armor & source){*this = source;} //Copy contructor
		armor& operator =(const armor & source); //Assignment operator overload
		void buy(deque<shared_ptr<product>> & ); // Buy function
		void request_upgrade(); //Upgrade function
		void negotiate_price(); // Negotiates the price of item function
		void display() const; //Display function
		void menu(deque<shared_ptr<product>> & cart); // Menu function

		
	private:
		int health_bonus;
};

//weapon class
class weapon : public product {

	public:
		weapon();//default constructor
		weapon(const string source, string description, int cost, int dig, int damage);//constructor with arguments
		weapon(const weapon & source){*this = source;} //Copy contructor
		weapon& operator =(const weapon & source);//Assignment operator overload
		void buy(deque<shared_ptr<product>> & ); // Buy function
		void request_upgrade(); //Upgrade function
		void negotiate_price(); // Negotiates the price of item function
		void display() const; //Display function
		void menu(deque<shared_ptr<product>> & cart);// Menu function


	private:
		int damage_bonus;
};

//potion Class
class potion: public product{

	public:
		potion();//default constructor
		potion(const string source, string description, int cost, int dig, string status);//constructor with arguments
		potion(const potion & source){*this = source;} //Copy contructor
		potion& operator =(const potion & source);//Assignment operator overload
		void buy(deque<shared_ptr<product>> & );// Buy function
		void request_upgrade();//Upgrade function
		void negotiate_price();// Negotiates the price of item function
		void display() const; //Display function
		void bulk_buy(deque<shared_ptr<product>> & ); //Bulk buy item function, unique function for RTTI
		void menu(deque<shared_ptr<product>> & cart);// Menu function
		void RTTI(deque<shared_ptr<product>> & cart);// This function was made to use and test RTTI


		
	private:
		string effect;
}; 
