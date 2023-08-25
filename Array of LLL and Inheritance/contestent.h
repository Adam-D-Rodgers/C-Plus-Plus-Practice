//Adam Rodgers, 
//This file stores all the .h data for all the other classes but race.h
//The contestent class is the base class for all the racers.

#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib> 
#include <ctime>
#include <random>
#include <list>
#include <vector>
using std::vector;
using std::list;
using std::string;


//contestent class
class contestent {
	public:
		contestent();
		contestent(const char * source, char * terrain_p, char * terrain_m);
		~contestent();
		contestent(const contestent & source);
		contestent& operator =(const contestent & source);
	
		int display() const;

	protected:
		char * name;
		int mile;
		char * t_plus;
		char * t_minus; 
};

//array of LLL's node
struct a_node {
	string data;
	a_node * next;

	a_node();
};

//array of leaner linked lists
class array_LLL {
	public:
		array_LLL();
		~array_LLL();
		array_LLL(const array_LLL & source);
		array_LLL& operator =(const array_LLL &	 source);
		void make_array();
		void displayW();
		int check_track(char *, char *, int) const;
		

	private:
		a_node ** track;
		void display(a_node *);
		void copy(a_node *, a_node *&);
		void del(a_node *&);
};

//toddler class
class toddler : public contestent{

	public:
		toddler();
		~toddler();
		toddler(char *, char *);
		toddler(const toddler & source);
		toddler& operator =(const toddler & source);
		void events();
		int display() const;
		int check_win(int);
		void terrain_effect(const array_LLL * track);

	private:
		char * last_name;
		
};

//node for CLL
struct node {
		toddler data;
		node * next;
};	

//CLL class
class CLL {
	public:
		CLL();
		~CLL();
		CLL(const CLL & source);
		CLL& operator =(const CLL & source);

		void W_CLL(array_LLL * track);
		int add(const toddler & input);
		

	private:
		node * rear;
		int finished_toddlers;
		void i_CLL(node * , node * curr, array_LLL * track);
		void copy(node *, node *);
		void del(node *);
};

//Robot class
class robot : public contestent {

	public:
		robot();
		robot(char *);
		void events();
		int display() const;
		int check_win(int);
		void terrain_effect(const array_LLL * track);

	private:
		
};

//Rex Class
class rex: public contestent{

	public:
		rex();
		rex(char *);
		void events();
		int display() const;
		int check_win(int);
		void terrain_effect(const array_LLL * track);

	private:
}; 
