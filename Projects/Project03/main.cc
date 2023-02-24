/*************************************************************************
	This is the main for Project 3, which asks you to build a container 
	that holds a list of people requesting their flu vaccines.

    The Appointments, which are actually appoinment requests, are always 
	kept in order, so they never need to be sorted since they are always 
	inserted in the order where they go. You will also need the files:

	datetime.h
	datetime.cc
	appointment.h
	apointment.cc
	node.h

    in order to do this project.
	
	You will be writing both the .h and the .cc file for the container.

	John Dolan
	Patricia Lindner	February 2023
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "appointment.h"
#include "node.h"
#include "WaitList.h"

using namespace std;

// This function displays the menu and returns the user's choice
char menu();

int main(){
    char choice, ch;
    Appointment ap;
    string patientname;
    ifstream fin;
    ofstream fout;
    string username, filename, fullname;

	cout << "Welcome to the Flu Vaccine Manager.\n\n";
	cout << "Begin by entering your backup file name: ";
	getline(cin, username);
	filename = username + ".txt";

	// The default constructor is called here
	WaitList pharmacy;
	// load the list from a file
    fin.open(filename.c_str());
    if(!fin.fail()){
        pharmacy.load(fin);
        fin.close();
	}

	choice = menu();
	while(choice != '0'){
	    switch(choice){
			case '1':
				cout << "Enter the appointment information.\n";
				cin >> ap;
				pharmacy.add(ap);
				break;

			case '2':
				pharmacy.display(cout);
				break;

			case '3':
				cout << "Enter the name of the person who is to be removed.\n ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				getline(cin, patientname);
				ap = pharmacy.find(patientname);
				if(ap != Appointment()){
					cout << ap;
					cout << "Do you want your remove this appointment request? (y/n)\n";
					cin >> ch;
					if(tolower(ch) == 'y'){
						pharmacy.remove(patientname);
					}
				}
				else{
					cout << "Appointment not found\n";
				}

				break;

			case '4':
				cout << "\nNumber waiting  = " << pharmacy.waiting() << endl << endl;
				break;

			case '5':
				cout << "\nThe longest wait = ";
				convert_minutes(pharmacy.longest_wait());
				cout << endl;
				break;

			case '6':
				cout << "\nThe average wait time of all in line = ";
				convert_minutes(pharmacy.average_wait());
				cout << endl;
				break;

			case '7':
				cout << "\nThe oldest person in line is " << pharmacy.oldest() << " years old.\n\n";
				break;

			case '8':
				cout << "\nThe youngest person in line is " << pharmacy.youngest() << " years old.\n\n";
				break;

			case '9':
				cout << "\nThe average age of those in line is " << pharmacy.average_age() << " years old.\n\n";
				break;

			case '0':
				cout << "Thank you for using the Appointment Manager.\n";
				break;

			case 't':{   // copy constructor test
				WaitList apcopy(pharmacy); // you must write all 3 of the Big 3
				cout << "\nEnter the name of the person who is to be removed.\n ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				getline(cin, patientname);
				apcopy.remove(patientname);
				apcopy.display(cout);
				cout << "Number waiting = " << apcopy.waiting() << endl << endl;
				break;
			}  // copy goes out of scope

			default:
				cout << "Not an option.\n";
				break;
		} // end of the switch
	    choice = menu();
	} // end of the senteniel while loop

	// save data to a file
    fout.open(filename.c_str());
    if(!fout.fail())
		pharmacy.save(fout);
    else
		cout << "Problem with saving data!\n";
    fout.close();

	return 0;
}

char menu(){
    char choice;

    cout << "Choose from the following options:\n";
    cout << "1) Add an appointment request to the list.\n";
    cout << "2) Display all the appointment requests in the list.\n";
    cout << "3) Remove an appointment request.\n";
    cout << "4) Display number of people waiting in line.\n";
    cout << "5) Display wait time of longest waiting.\n";
    cout << "6) Display the average wait time for all currently in line.\n";
    cout << "7) Display the age of the oldest person in the list. \n";
    cout << "8) Display the age of the youngest person in the list. \n";
    cout << "9) Display the average age of those in the list. \n";
    cout << "0) Quit - saving all changes.\n";
    cin >> choice;

    return choice;
}