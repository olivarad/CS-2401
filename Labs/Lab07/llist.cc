/************************************************************************
     This is the implementation file for the LList class which is a 
container based on a doubly linked list. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.

	John Dolan		Ohio University		Spring 2018
************************************************************************/
#include <iostream>
#include "llist.h"
using namespace std;

// node constructor
node::node(int d, node* p, node* n){
	data_field = d;
	nextptr = n;
	previousptr = p;
}


// Llist functions
LList::LList(){
	head = tail = NULL;
	nodecount = 0;
}

LList::~LList(){
	node* rmptr;
	while(head != NULL){
		rmptr = head;
		head = head -> next();
		delete rmptr;
	}
}

LList::LList(const LList& other){ // Copy constructor
	if(other.head == NULL){ // Other is empty
		return; // Returns empty list
    }
	else{
		head = tail = new node(other.head -> data()); // Sets the head of the copied list
		for (node* cursor = other.head -> next(); cursor != NULL; cursor = cursor -> next()){ // Itterates through the other list
			tail -> set_next(new node(cursor -> data(), tail, NULL)); // Makes a new node and sets the data field to the passed int, previous to tail, but n to null
			tail = tail -> next(); // Makes the new node the end of the list
		}
	}
	nodecount = other.nodecount; // Copies nodecount
}

void LList::frontview()const{
    node* cursor = head;
    while (cursor != NULL){
		cout << cursor -> data() << "  ";
		cursor = cursor -> next();
    }
	cout << endl;
}

// The student is required to write the implementation of this function
void LList::rearview()const{
    node* cursor = tail;
    while (cursor != NULL){
		cout << cursor -> data() << "  ";
		cursor = cursor -> previous();
    }
	cout << endl;

}


void LList::add_item(int item){
    if(head == NULL){
		head = tail = new node(item); // Creates the first node
		nodecount++; // Increments node count
    }
    else if(item % 5 == 0 && nodecount > 3){
		int i = 0; // Creates an integer itterator
		node* cursor = head; // Node itterator
		while(i < nodecount / 2){ // Itterates until halfway through the list
			cursor = cursor -> next();
			i++;
		}
		cursor -> previous() -> set_next(new node(item, cursor -> previous(), cursor)); // Puts a node directly after the cursor
		cursor -> set_previous(cursor -> previous() -> next()); // Links the nodes back up
		nodecount++; // Increments node count
    }
    else{
		tail -> set_next(new node(item, tail)); // Makes a new node and sets the data field to the passed int, previous to tail, but n to null
		tail = tail -> next(); // Makes the new node the end of the list
		nodecount++; // Increments node count
    }
}