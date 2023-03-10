/*************************************************************************
    This is the header file for a class that holds a doubly linked list
    of integers. Above the declaration of that class you will find a 
    declaration of a node class that is used in the construction of that
    list.

    The student will be asked to complete some incomplete parts of this 
    list class. 

	John Dolan			Spring 2018		School of EECS Ohio University
	Patricia Lindner	March 2023
			
*************************************************************************/

#include <iostream>

class node{
    public:
		node(int d = 0, node* p = NULL, node* n = NULL);

		int data() {return data_field;}
		node* previous() {return previousptr;}
		node* next() {return nextptr;}

		void set_data(int d) {data_field = d;}
		void set_previous(node* p) {previousptr = p;}
		void set_next(node* n) {nextptr = n;}

    private:
		int data_field;
		node *nextptr;
		node *previousptr;
};

class LList{
    public:
		LList();
		~LList();
		LList(const LList& other); // Copy Constructor

		void add_item(int item);
		void frontview()const;
		void rearview()const;

		int size()const {return nodecount;}

    private:
		node* head;
		node* tail;
		int nodecount;
};