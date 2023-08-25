//Adam Rodgers, 
//This file manages the array of linear linked list that stores the terrain.
//As well as the CLL that stores the toddler racers

#include "contestent.h"
using namespace std;

//a_node defualt constructor
a_node::a_node(){
  data = "";
	next = nullptr;
}

///default constructor
array_LLL::array_LLL() {
  track = new a_node * [5];
  track[0] = nullptr;
  track[1] = nullptr;
  track[2] = nullptr;
  track[3] = nullptr;
  track[4] = nullptr;
}

//destructor
array_LLL::~array_LLL(){
  for(int i = 0; i < 5; ++i){
    del(track[i]);
  }  
  delete [] track;
}

//copy constructor
array_LLL::array_LLL(const array_LLL & source){
  track = new a_node * [5];
  track[0] = nullptr;
  track[1] = nullptr;
  track[2] = nullptr;
  track[3] = nullptr;
  track[4] = nullptr;
  *this = source;
}

//assignment operator 
array_LLL & array_LLL::operator=(const array_LLL & source){
  if(this == &source) return *this;
  for(int i = 0; i < 5; ++i){
    del(track[i]);
    track[i] = new a_node;
    track[i]->data = source.track[i]->data;
    copy(source.track[i]->next, track[i]->next);
  }
  return *this;
}

//delete function
void array_LLL::del(a_node *& curr){
  if(!curr) return;
  del(curr->next);
  delete curr;
  curr = nullptr;
}

//copy function
void array_LLL::copy(a_node * curr, a_node *& my_curr) {
  if(!curr) return;
  my_curr = new a_node;
  my_curr->data = curr->data;
  copy(curr->next, my_curr->next);
}

//fill array function
void array_LLL::make_array() {
    string data[5] = {
        "STREETS", "MOUNTAINS", "PLAINS", "TUNNELS", "DREAMLAND"
    };

    string details[5][2] = {
        {"a roundabout", "a road maze"},
        {"a sheer cliff", "ragged rock terrain"},
        {"a few small hills", "antelope grazing on the track"},
        {"a lava jump!", "a pitch black tunnel"},
        {"a rainbow road", "a track made of clouds"}
    };

    for (int i = 0; i < 5; i++) {
        track[i] = new a_node;
        track[i]->data = data[i];
        track[i]->next = new a_node;
        track[i]->next->data = details[i][0];
        track[i]->next->next = new a_node;
        track[i]->next->next->data = details[i][1];
    }
}

//display function wrapper
void array_LLL::displayW(){
  for(int i = 0; i < 5; ++i){
    cout << endl << track[i]->data << ": " << endl;
    display(track[i]->next);
  }
}

//display function
void array_LLL::display(a_node * curr){
  if(!curr) return;
  cout << curr->data << endl;
  display(curr->next);
}

//check the terrain effect for racer classes
int array_LLL::check_track(char * gain, char * loss, int spot) const{
  if (strcmp(gain, track[spot]->data.c_str()) == 0)
  {
    return 1;
  }
  if (strcmp(loss, track[spot]->data.c_str()) == 0)
  {
    return 2;
  }
  return 0;
}


//defualt constructor 
CLL::CLL() : rear(nullptr), finished_toddlers(0)
{
}

//destructor
CLL::~CLL() {
  if(rear){
    node * curr = rear->next;
    rear->next = nullptr;
    rear = nullptr;
    del(curr);
  }
}

//copy constructor
CLL::CLL(const CLL &source)
{
  *this = source;
}

//assignmnet operator
CLL &CLL::operator=(const CLL &source)
{
  if(this == &source || !source.rear) return *this;
  this->~CLL();
  add(source.rear->data);
  copy(source.rear->next, source.rear);
  return *this;
}

//delete function
void CLL::del(node * curr) {
  if(!curr) return;
  node * hold = curr->next;
  delete curr;
  del(hold);
  return;
}

//copy function
void CLL::copy(node * source_rear, node * true_rear) {
  if(source_rear == true_rear) return;
  add(source_rear->data);
  copy(source_rear->next, true_rear);
  return;
}

//add function
int CLL::add(const toddler &input)
{
  if (!rear) {
    rear = new node;
    rear->data = input;
    rear->next = rear;
  }
  else {
    node *hold = rear->next;
    rear->next = new node;
    rear->next->data = input;
    rear = rear->next;
    rear->next = hold;
  }
  return 1;
}

//simulates the race wrapper
void CLL::W_CLL(array_LLL * track) {
  i_CLL(rear, rear->next, track);
}

//simulates the race for toddlers
void CLL::i_CLL(node *rear, node *curr, array_LLL * track) {
  if (rear == nullptr)
    return;

  if (curr->data.check_win(finished_toddlers)) {
    ++finished_toddlers;
  }
  else {
    curr->data.terrain_effect(track);
    curr->data.events();
  }

  if (this->rear != curr) {
    i_CLL(rear, curr->next, track);
  }
}

