//************************************************************************
//	Implementation file for the Numlist class, which 
//	allows programmers to store a list of numbers that they
//	choose to have sorted if they like.
//
//	January 2013		John Dolan
//  January 2023		Patricia Lindner
//	Ohio University		EECS
//***********************************************************************/
#include "numlist.h"
using namespace std;

// Constructor
NumList::NumList(){
	used = 0;
}

void NumList::insert(int num){
	if(used < CAPACITY){
		data[used] = num;
		used++;
	}
	else{
		cout << "Error. List capacity has been reached.\n";
	}
}

void NumList::load_from_file(istream& ins){
	string line; // String to track the data for each line
	while(!ins.eof()){ // Runs until the file is out of data
		ins >> data[used]; // Recieves data from the file and puts it in the data array
		used++; // itterates used
	}
	used--; // Gets rid of extra data from newline
}


void NumList::save_to_file(ostream& outs){
	for(long unsigned int i = 0; i < used; i++){
		outs << data[i] << endl;
	}
}

void NumList::see_all()const{
	if(used == 0){
	    cout << "Empty list.\n";
	}
	else{
	    for(size_t i = 0; i < used; ++i)
		cout << data[i] << endl;
	}
}

int NumList::get_item(size_t index)const{
	if(index < used){
		return data[index];
	}
	else{
		return -1;
	}
}
	
void NumList::i_sort(){
	for (long unsigned int i = 1; i < used; i++)
	{
		int next = data[i];
		// Move all larger elements up
		long unsigned int j = i;
		while (j > 0 && data[j - 1] > next)
		{
			data[j] = data[j - 1];
			j--;
		}
		// Insert the element
		data[j] = next;
	}
}
