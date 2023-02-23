#include <fstream>
#include <iostream>
#include <string>
#include "numlist.h"

using namespace std;

int main(){
    NumList nums; // An empty NumList object
    string fileName; // String to store the file name
    ifstream ins; // A input filestream
    int insert; // An integer to be used in the insert function

    cout << "please provide a filename for input and output: "; // Prompts for a fileName
    cin >> fileName; // Recieves fileName
    ins.open((fileName + ".dat").c_str()); // Opens a file for reading
    nums.NumList::load_from_file(ins); // Loads the file data into an array
    ins.close(); // Closes the input file

    cout << "please provide a number to be inserted: "; // Prompts for a number to insert
    cin >> insert; // Gets the number
    nums.NumList::insert(insert); // Inserts a user provided number
    cout << "please provide a number to be inserted: "; // Prompts for a number to insert
    cin >> insert; // Gets the number
    nums.NumList::insert(insert); // Inserts a user provided number
    cout << "please provide a number to be inserted: "; // Prompts for a number to insert
    cin >> insert; // Gets the number
    nums.NumList::insert(insert); // Inserts a user provided number  

    nums.NumList::i_sort(); // runs the i_sort function

    nums.NumList::see_all();

    ofstream outs; // An output stream
    outs.open((fileName + "sorted.dat").c_str()); // Opens a file for writing
    nums.NumList::save_to_file(outs); // Saves the data to the output file
    outs.close(); // Closes the ouput file

    return 0;
}