/*************************************************************************
    This is the main for our Plant Nursery project. You will be able to 
	see, by reading the code below, the names and parameters of the 
	functions that you will be creating in your PlantNursery class
	(13 in total).

    You are NOT to alter this file except to uncomment function calls

	Patricia Lindner	Ohio University EECS	January 2023
*************************************************************************/
/*************************************************************************
    This version has been modified by commenting out all the function
    calls on the PlantNursery object, allowing you to develop, compile 
	and test each function one at a time. After you write a function 
    uncomment the call to that function, compile your project and test
    it with that option.
*************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "plant.h"
#include "plantNursery.h"
using namespace std;

/* This function shows the user the menu, asks them to enter their 
choice and then returns the integer value of that choice. */
int menu();

int main(){
    Plant tmp;
    ifstream ifs;
    ofstream ofs;
    string in_file;
    int choice;  // user menu choice
	int amt; // the amount to change the stock of a Plant by
    string p_name, p_color;   // Plant name and color to be removed from the nursery
    string plant_type; // used in listing all plants of a certain type
	Date before_date;

    cout << "Please enter the name of your inventory file (no extension): ";
    cin >> in_file;

    PlantNursery myplants; // A default PlantNursery is constructed
    in_file = in_file + ".txt";
    ifs.open(in_file.c_str());

	// if no file this is first running for this user
    if(!ifs.fail()){ 
		myplants.load_from_file(ifs); // Loads plant data from the provided .txt into the Plant array in the PlantNursery class
		ifs.close();
    }

    do{
		choice = menu();
		switch(choice){
			case 1:
				myplants.show_all(cout);
				break;
			case 2:
				myplants.add_plant(cin);
				break;
			case 3:
				cout << "Enter the name and color of the Plant to be removed (each entry should be followed by the return key): ";
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				getline(cin, p_name);
				getline(cin, p_color);
				myplants.remove(p_name, p_color);
				break;
			case 4:
				cout << "Enter the name and color of the Plant (each entry should be followed by the return key): ";
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				getline(cin, p_name);
				getline(cin, p_color);
				cout << "Enter the amount by which you want to adjust the stock: ";
				cin >> amt;
				myplants.change_stock_amt(p_name, p_color, amt);
				break;
			case 5:
				myplants.name_sort();
				break;
			case 6:
				myplants.date_sort();
				break;
			case 7:
				myplants.stock_sort();
				break;
			case 8:
				cout << "Enter the color: ";
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				getline(cin, p_color);
				myplants.show_plants(p_color);
				break;
			case 9:
				cout << "Enter the date: ";
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				cin >> before_date;
				myplants.show_before(before_date);
				break;
			case 10:
				cout << "Enter the plant: ";
				while(cin.peek() == '\n' || cin.peek() == '\r'){
					cin.ignore(); // clear out leftover newlines
				}
				getline(cin, p_name);
				myplants.show_colors(p_name);
				break;
			case 11:
				cout << "The average stock amount is: " << myplants.average() << endl;
				break;
			case 0:
				cout << "Thank you for using the Plant Nursery inventory system.\n";
				cout << "All alterations to your data will now be saved.\n";
				break;
			default:
				cout << "Invalid choice. Please choose again.\n";
				break;
		} // bottom of the switch
    } while(choice != 0);

	ofs.open(in_file.c_str());
	if(!ofs.fail()){
		myplants.save(ofs);
	    ofs.close();
	}

	return 0;
}

int menu(){
    int choice;
	
    cout << "Your Plant Nursery. Please choose from the following:\n";
    cout << " 1) See a list of all plants in stock.\n";
    cout << " 2) Add a new plant that just came in stock.\n";
    cout << " 3) Remove a plants that is sold out.\n";
    cout << " 4) Change the stock amount of a plant.\n";
    cout << " 5) Sort plants alphabetically by name.\n";
    cout << " 6) Sort plants by the date they came in stock.\n";
    cout << " 7) Sort plants by the quantity in stock.\n";
    cout << " 8) View all plants of a certain color.\n";
    cout << " 9) View all plants that came in stock before a certain date.\n";
    cout << "10) View all the colors of a certain plant.\n";
	cout << "11) View the average stock amount.\n";
    cout << " 0) Quit.\n";

    cin >> choice;

    return choice;
}