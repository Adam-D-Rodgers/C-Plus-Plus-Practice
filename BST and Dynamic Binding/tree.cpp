//Adam Rodgers, 8/14/2023
//This is the .cpp file for the tree ADT
#include "tree.h"

//Default Constructor
tree::tree(): root(nullptr){
}

//default Distructor
tree::~tree(){
	//remove_all(root);	//Remove call function not called as smart pointers were used.
	root = nullptr;
}

void tree::make_store(){
	shared_ptr<product> items[9]; //Makes shared pointers for data and then inserts them
	items[0] = make_shared<armor>("BLACK HELMET", "a black helmet clad in gold", 50, 101, 30);
	items[1] = make_shared<armor>("TINY GOLDEN CHESTPLATE", "A gold chestplate that looks about the right size for a toddler?", 100, 102, 20);
	items[2] = make_shared<armor>("LEATHER LEGGING", "a simple pair of leather leggings", 20, 103, 10);
	items[3] = make_shared<weapon>("FAKE EXCALIBUR", "It is clearly just a iron sword, but the shop keep claims it is the legendary sword excalibur...", 100, 201, 10);
	items[4] = make_shared<weapon>("STEEL SWORD", "A study steel sword", 30, 202, 40);
	//items[5] = make_shared<weapon>("STEEL SWORD", "A study steel sword", 30, 202, 40); //Exception handling check
	items[5] = make_shared<weapon>("SILVER SWORD", "A silver sword great at killing monsters", 120, 203, 70);
	items[6] = make_shared<potion>("Healing Potion", "A small red potion", 10, 301, "This potion provides a small amount of healing");
	items[7] = make_shared<potion>("Damage Potion", "A small blue potion", 10, 302, "This potion provides a small damage buff");
	items[8] = make_shared<potion>("Invisibility Potion", "A small clear potion", 10, 303, "This potion makes the user invisible for 3 minutes");
	for(int i = 0; i < 9; ++i){ //insertion loop
		try {insertW(items[i]);}
		catch(int val){
			cout << "No input source" << endl;
		}
	}
}

//Insert function wrapper
int tree::insertW(shared_ptr<product>& source){
	if(!source) throw 10;
	try { insert(root, source); }
	catch(int x){
		cout << "DUPLICATE VALUE" << endl;
	}
	return 1;
}

//insert function
int tree::insert(shared_ptr<node>& root , shared_ptr<product>& source){
	if(!root){ //base case
		root = make_shared<node>();
		root->set_data(source);
		root->set_right(nullptr);
		root->set_left(nullptr);
		return 1;
	}
	if(source->get_name() < root->get_name()){ //sorts by name
		insert(root->get_left(), source);
	}
	else if(source->get_name() > root->get_name()){
		insert(root->get_right(), source);
	}
	else{
		throw 10;  //If it is a duplicate
	}
	return 1;
}

//Display All function wrapper
int tree::displayW() const{
	cout << endl << endl << "THIS IS ALL THE ITEMS IN THE STORE:" << endl;
	display(root);
	return 0;
}

//Display All function
int tree::display(shared_ptr<node> root) const{
	if(!root) return 1;
	root->display();
	display(root->get_left());
	display(root->get_right());
	return 0;
}

//Purchase function wrapper
int tree::purchaseW(int search, deque<shared_ptr<product>> & cart){
	purchase(root,search, cart);
	return 1;
}

//Goes to the wanted node and uses dynamic binding to call function
int tree::purchase(shared_ptr<node>& root, int search, deque<shared_ptr<product>> & cart){
	if(!root) return 1;
	if(search == root->get_code()){
		root->display_menu(cart);
	}
	purchase(root->get_left(), search, cart);
	purchase(root->get_right(), search, cart);
	return 0;
}

//Remove function wrapper
int tree::removeW(string search){
	if(!root) return 0;
	return remove(root, search);
}

//Remove searched term function
int tree::remove(shared_ptr<node>& root, string search){
	if(!root) return 0;
	if(search == root->get_name()){ //If it is the searched name
		if(!root->get_right() && !root->get_left()){ //if it has a no child
			root.reset();
		}
		else if(root->get_left() && !root->get_right()){ //if it has a left child
			shared_ptr<node> hold = root->get_left();
			root.reset();
			root = hold;
		}
		else if(root->get_right() && !root->get_left()){//if it has a right child
			shared_ptr<node> hold = root->get_right();
			root.reset();
			root = hold;
		}
		else{ //if it has both children find ios and delete it and then set ios data into current node
			shared_ptr<product> ios_val;
			iosW(root, ios_val);
			root->set_data(ios_val);
		}
	}
	else if(search < root->get_name()){ //search by sorted name if less then 
		remove(root->get_left(), search);
		return 1;
	}
	else if(search > root->get_name()){//search by sorted name if greater then 
		remove(root->get_right(), search);
		return 1;
	}
	return 0;
}

//In order successor function wrapper
int tree::iosW(shared_ptr<node>& root, shared_ptr<product> & ios_val){
	if(!root) return 0;
  if(!root->get_right()) return 0;

  return ios(root->get_right(), ios_val);
}

int tree::ios(shared_ptr<node>& root, shared_ptr<product> & ios_val){
	if(!root->get_left()){ //if there is no left child
		ios_val = root->get_data(); //store the nodes data and then delete the node, and reconnect 
		shared_ptr<node> hold_right = root->get_right();

		root = nullptr;
		root = hold_right;
		return 1;
	}
	ios(root->get_left(), ios_val);
	return 1;
}

//REmove all function wrapper
int tree::remove_all(){
	remove_all(root);
	return 1;
}

//Remove all function 
int tree::remove_all(shared_ptr<node>& root){
	if(!root) return 0;
	remove_all(root->get_left());
	remove_all(root->get_right());
	root.reset();
	return 1;
}
