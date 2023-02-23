/*************************************************************************
    This is the implementation file for the plantNursery class. For more 
		information about the class see plantNursery.h.

	Olivia Radecki	Ohio University EECS	January 2023
*************************************************************************/

#include "plantNursery.h"
using namespace std;

void PlantNursery::load_from_file(std::istream& ins){ // Load Plant data from the provided file stream into the array of Plant data in the PlantNursery class
	while(!ins.eof()){ // Runs until the end of the input file
		plants[used].input(ins); // Populates the plant entry
		used ++; // Itterates used
	}
	used--; // Decrements used to ignore the eof that previously created an extra blank plant entry
}

void PlantNursery::show_all(std::ostream& outs)const{ // Displays all collected Plant information stored in the Plant array of the PlantNursery class
    for(int i = 0; i < used; i++){ // Runs through every Plant in the array
		plants[i].output(outs); // Calls the output function in the plant class
		outs << endl; // Newline for formatting
	}
}

void PlantNursery::add_plant(std::istream& ins){ // Adds a single new plant to the plant array in the PlantNursey class
	plants[used].input(ins); // Calls the input function for Plant members
	used++; // Increments used
}

void PlantNursery::remove(std::string p_name, std::string p_color){ // Removes a single plant from the plant array after checking where it is and if it exsists
	Plant temp;
	for(int i = 0; i < used; i++){ // Runs through every spot in the plant array
		if(plants[i].get_name() == p_name && plants[i].get_color() == p_color){ // Plant Match
			for(int j = i; j < used; j++){ // Itterates through the list starting at the index to be removed
				temp = plants[j + 1]; // Writes the end of the file to the temporary plant object
				plants[j] = temp;
			}
			used--; // Decrements used
		}
		else if(i == (used)){ // There was no plant match and everything in the array was searched
			cout << "No match found\n"; // Informs the operator that no such plant is currently being housed in the greenhouse file system
		}
	}
}

void PlantNursery::change_stock_amt(std::string p_name, std::string p_color, int amt){ // Changes the stock amount of a plant in the plant array should the plant exsist
	cout << endl; // Newline for formatting
    for(int i = 0; i < used; i++){ // Runs through every spot in the plant array
		if(plants[i].get_name() == p_name && plants[i].get_color() == p_color){ // Plant Match
			plants[i].change_stock(amt); // Calls the change_stock function from the plant class
		}
		else if(i == (used - 1)){ // There was no plant match and everything in the array was searched
			cout << "No match found\n"; // Informs the operator that no such plant is currently being housed in the greenhouse file system
		}
	}
}

void PlantNursery::name_sort(){
	Plant temp; // Temporary storage Plant object
    for(int i = 0; i < used; i++) // Itterates through all of the array
    {
        for(int j = 1; j < used - i; j++) // Itteration that skips the first index
        {
            if((plants[j-1].get_name()).substr(0, 1) > (plants[j].get_name()).substr(0, 1)) // Compares for alphabetization based on the ascii table
            {
                temp = plants[j-1];
                plants[j-1] = plants[j];
                plants[j] = temp;
            }
        }
    }
}

void PlantNursery::date_sort(){
	Plant temp; // Temporary storage Plant object
    for(int i = 0; i < used; i++) // Itterates through all of the array
    {
        for(int j = 1; j < used - i; j++) // Itteration that skips the first index
        {
            if(plants[j-1].get_cameIn() > plants[j].get_cameIn()) // Compares for alphabetization based on the ascii table
            {
                temp = plants[j-1];
                plants[j-1] = plants[j];
                plants[j] = temp;
            }
        }
    }	
}

void PlantNursery::stock_sort(){
	Plant temp; // Temporary storage Plant object
    for(int i = 0; i < used; i++) // Itterates through all of the array
    {
        for(int j = 1; j < used - i; j++) // Itteration that skips the first index
        {
            if(plants[j-1].get_stock() > plants[j].get_stock()) // Compares for alphabetization based on the ascii table
            {
                temp = plants[j-1];
                plants[j-1] = plants[j];
                plants[j] = temp;
            }
        }
    }	
}

void PlantNursery::show_plants(std::string color)const{
    for(int i = 0; i < used; i++){ // Itterates through all plants
        if(color == plants[i].get_color()){ // Color match
            cout << plants[i].get_name() << endl; // Output the plant name
        }
    }
}

void PlantNursery::show_before(Date date)const{
    for(int i = 0; i < used; i++){ // Itterates through all plants
        if(plants[i].get_cameIn() < date){ // Plant came in before the specified date
            plants[i].output(cout); // Output the plant data        
        }
    }
}

void PlantNursery::show_colors(std::string name)const{
    for(int i = 0; i < used; i++){ // Itterates through all plants
        if(plants[i].get_name() == name){ // Plant name matches
            cout << plants[i].get_color() << endl; // Output the plant color      
        }
    }
}

double PlantNursery::average(){
    double count = 0;
    for(int i = 0; i < used; i++){ // Itterates through all plants
        count += plants[i].get_stock(); // Adds the stock for each plant
    }
    return count / used; // Returns the average

}

void PlantNursery::save(std::ostream& outs)const{
for(int i = 0; i < used; i++){ // Runs through every Plant in the array
		plants[i].output(outs); // Calls the output function in the plant class
    }
}