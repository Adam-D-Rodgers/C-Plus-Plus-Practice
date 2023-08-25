//Adam Rodgers, 8/14/2023
//This is the .h that manages the tree class. 

#include "product.h"
using namespace std;

//Node to create linked list
class node {
  public:

    node(): data(nullptr), right(nullptr), left(nullptr) {} //default contructor

    void set_data(const shared_ptr<product> source){ //Sets the data 
      data = source;
    }

    string get_name(){ //Calls the get_name function 
      return data->get_name();
    }

    int get_code(){  //Calls the get_code function
      return data->get_code();
    }

    void display_menu(deque<shared_ptr<product>> & cart){ //Calls the virtual menu function
      data->menu(cart);
    }

    shared_ptr<node>& get_right(){ // get right function
      return right;
    }

    shared_ptr<node>& get_left(){ // get left function
      return left;
    }

    shared_ptr<product> get_data(){ // get data function
      return data;
    }

    void set_right(shared_ptr<node> input){ //set nect function
      right = input;
    }

    void set_left(shared_ptr<node> input){ //set left function
      left = input;
    }

    void display(){ //Calls display function
      data->display();
    }
    
  private:
    shared_ptr<product> data;
    shared_ptr<node> right;
    shared_ptr<node> left;
};
//Main class of tree table
class tree{
	public:
		tree();
		~tree();

    void make_store(); //Makes the store and sets its data
		int insertW(shared_ptr<product> & source); //Insert wrapper function
		int displayW() const; //Display wrapper function
		int purchaseW(int search, deque<shared_ptr<product>> &); //Purchase wrapper function
		int removeW(string search); //Remove searched node wrapper
    int remove_all(); //Remove all function
	private:
		int insert(shared_ptr<node>& root , shared_ptr<product>& source); // Insert function
		int display(shared_ptr<node> root) const; // Display function
		int purchase(shared_ptr<node>& root, int search, deque<shared_ptr<product>> &); // Purchase function
		int remove(shared_ptr<node>& root, string search); // remove function
		int remove_all(shared_ptr<node>& root); //remove all function
    int iosW(shared_ptr<node>& root, shared_ptr<product> &); //find ios wrapper
		int ios(shared_ptr<node>& root, shared_ptr<product> &); //Find and delete ios and set data function

		shared_ptr<node> root;
};
