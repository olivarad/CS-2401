/*************************************************************************
    This is the implementation file for the Plant class. For more 
		information about the class see plant.h.
    Students are expected to implement the input and output functions
		below.

	Patricia Lindner	Ohio University EECS	January 2023
*************************************************************************/
#include "plant.h"
using namespace std;

Plant::Plant(string n, string c, Date i, int s){
	name = n;
	color = c;
	cameIn = i;
	stock = s;
}

// Input and output functions
void Plant::input(std::istream& ins){
	// Writes data from the instream to the name, color, cameIn, and stock of the provided plant object
	if (&ins != &cin) { // ins is not cin
		getline(ins, name);
		getline(ins, color);
		ins >> cameIn;
		ins >> stock;
		ins.ignore(); // Used to ignore a single return error which threw an error after one run of this function.
	}
	else{
		ins.ignore(); // Allows the program to ignore the newline character to run propperly
		cout << "Please provide a plant name: "; // Prompt for a plant name
		getline(ins, name);
		cout << "Please provide a plant color: "; // Prompt for a plant color
		getline(ins, color);
		cout << "Please provide the processing date in (dd/mm/yyyy): "; // Prompt for a date
		ins >> cameIn;
		cout << "Please provide a quantity: "; // Prompt for quantity
		ins >> stock;
		ins.ignore(); // Used to ignore a single return error which threw an error after one run of this function.
	}
}

void Plant::output(std::ostream& outs)const{
	if (&outs == &cout) { // outs is cout
		outs << "plant: " << name << endl; // Outputs plant name
		outs << "color: " << color << endl; // Outputs plant color
		outs << "came in: " << cameIn << endl; // Outputs when the plant came in
		outs << "quantity in stock: " << stock << endl; // Outputs the quantity in stock
}

	else{ // outs is a file stream
		outs << name << endl; // Outputs plant name
		outs << color << endl; // Outputs plant color
		outs << cameIn << endl; // Outputs when the plant came in
		outs << stock << endl; // Outputs the quantity in stock
	}
}

ostream& operator << (ostream& outs, const Plant& p){
	p.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Plant& p){
	p.input(ins);
	return ins;
}