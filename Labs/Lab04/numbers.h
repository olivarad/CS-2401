/*************************************************************************
	A little class that holds a dynamic array of numbers.
	I have provided a start here, you need to write the function
		implementations. DO NOT remove the byte_count lines that are
		already in a few of the functions.


    John Dolan			Spring 2013		CS2401 Lab Assignment 4
	Patricia Lindner	Fall 2021
*************************************************************************/

#include <iostream>
#ifndef NUMBERS_H
#define NUMBERS_H

size_t byte_count = 0;
class Numbers{
    public:
		Numbers(std::size_t used = 0, std::size_t capacity = 5); //l is a pointer for unsigned long
		~Numbers(); // Deconstructor
		void add(unsigned long item);
		void resize();
		void remove_last();
		void display(std::ostream& outs);
		unsigned long* reveal_address()const;
		void operator = (const Numbers& other);

    private: 
		unsigned long * data; // Unsigned long pointer
		std::size_t used;
		std::size_t capacity;

};

Numbers::Numbers(std::size_t u, std::size_t c){

	byte_count += 5 * sizeof(unsigned long);
	data = new unsigned long[c];
	used = u;
	capacity = c;
}

Numbers::~Numbers(){ // Deconstructor
	byte_count = byte_count - (capacity * sizeof(unsigned long));
    delete []data; // Deallocate the selected profile data 
}

void Numbers::add(unsigned long item){
	if (used == capacity){
		resize();
	}
	data[used] = item;
	used++;
}

void Numbers::resize(){

	byte_count += 5 * sizeof(unsigned long);
	unsigned long temp[capacity]; // Automatically allocated so it doesnt need to be deallocated

	for (std::size_t i = 0; i < capacity; i ++){ // itterates throught the entire array
        temp[i] = data[i]; // writes the array to the temporary stoarge variable
    }

    delete []data; // deallocates the data array

    data = new unsigned long[capacity + 5]; // Allocates memory

    for (std::size_t i = 0; i < capacity; i ++){ // itterates throught the entire array
        data[i] = temp[i]; // writes the array to the temporary stoarge variable
    }
	capacity += 5;
}

void Numbers::remove_last(){
	used--;
}

void Numbers::display(std::ostream& outs){
	for (std::size_t i = 0; i < used; i++){
		outs << data[i] << ' ';
	}
}

// You can leave this function alone
unsigned long *Numbers::reveal_address()const{
	return data;
}

void Numbers::operator = (const Numbers& other){ // Assignment operator
    if(this == &other){ // Check for self assignment
        return;
    }
    else{
        delete []data; // Deallocate old array

        used = other.used; // Reinitalizes used
        capacity = other.capacity; // Reinitializes capacity

        data = new unsigned long[other.capacity]; // Allocates memory for the new copied data

        for(std::size_t i = 0; i < other.used; i++){ // Copies data
        data[i] = other.data[i];
        }
    }
}

#endif