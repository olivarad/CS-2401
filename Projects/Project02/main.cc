/*************************************************************************
    Project 2		CS2401		Spring 2023

    This is the main for your second project, a project which works with 
    the concepts of a sequence class, an internal iterator, and a dynamic 
    array.

    In order to make this main work you will need to write two classes,
    one called Profile and one called InstaFollows. Going through the code
    below you should be able to figure out what member functions are
    needed for each. Also, since InstaFollows is holding dynamic memory you 
    will need to write the Big 3 for this class.

        Patricia Lindner    Spring 2023       Ohio University EECS
*************************************************************************/
    

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "profile.h"
#include "instafollows.h"
using namespace std;

int menu();
int menu2();

int main(){

    Profile p;
    InstaFollows myinsta;

    string profilename, username, filename;
    int choice, choice2;
    bool cutout;

    ifstream fin;
    ofstream fout;

	cout << "Welcome to your Instagram follows management system.\n\n";
	cout << "Begin by entering your username: ";
	getline(cin,username);

	filename = username + ".txt";
	fin.open(filename.c_str());

    if(!fin.fail()){
	    myinsta.load(fin);
    }
	fin.close();

	choice = 0;
	choice2 = 0;
	cutout = false;
    InstaFollows original(myinsta);

	while(choice != 9){
	    choice = menu();
	    switch(choice){
            case 1:
                cin >> p;
                myinsta.start();
                myinsta.insert(p);
                break;
            case 2:
                myinsta.show_all(cout);
                break;
            case 3: 
                myinsta.start();
                choice2 = 0;
                while(myinsta.is_item() && choice2 <= 5){
                    cout << myinsta.current();
                    choice2 = menu2();
                    if(choice2 == 1){
                        myinsta.remove_current();
                    }
                    else if(choice2 == 2){
                        if(!cutout){
                            cin >> p;
                        }
                        if(myinsta.is_profile(p)){
                            cout << "Already in list.\n";
                        }
                        else{
                            myinsta.insert(p);
                            cutout = false;
                        }
                    }
                    else if(choice2 == 3){
                        if(!cutout){
                            cin >> p;
                        }
                        if(myinsta.is_profile(p)){
                            cout << "Already in list.\n";
                        }
                        else{
                            myinsta.attach(p);
                            cutout = false;
                        }
                    }
                    else if(choice2 == 4){
                        p = myinsta.current();
                        myinsta.remove_current();
                        cutout = true;
                    }
                    else if(choice2 == 5){
                        myinsta.advance();
                    }
                    else{
                        cout << "Going back to main menu.\n";
                    }
                }
                break;
            case 4:
                myinsta.bday_sort();
                break;
            case 5:
                cout << "Enter the name for the profile: ";
                while(cin.peek() == '\n' || cin.peek() == '\r'){
                    cin.ignore();
                }
                getline(cin, profilename);
                p = myinsta.find_profile(profilename);
                if(p != Profile()) cout << p << endl;
                break;
            case 6:	
                original.show_all(cout);
                break;
            default:
                break;
		} // bottom of the switch
	} // bottom of the while

	fout.open(filename.c_str());
    if(!fout.fail()){
        myinsta.save(fout);
    }
	else{
	    cout << "Unable to save data.\n";
    }
	fout.close();

    return 0;
}
	
int menu(){
	int ans;

	cout << "Choose from the options below:\n";
	cout << "1 - Add a profile to the beginning of the list.\n";
	cout << "2 - See all the profiles you are following.\n";
	cout << "3 - Walk through the list, one profile at a time.\n";
	cout << "4 - Sort the profiles you follow by birthday.\n";
	cout << "5 - Find a profile so you can learn when they were born.\n";
	cout << "6 - See the list you started with in today's session.\n";
	cout << "9 - Leave the program.\n";

	cin >> ans;
    return ans;
}

int menu2(){
	int ans;

	cout << "What would like to do with this profile?\n";
	cout << "1 - Remove from the list.\n";
	cout << "2 - Insert a new or cut-out profile before this one.\n";
	cout << "3 - Put a new or cut-out profile after this one.\n";
	cout << "4 - Cut this profile from the list to be inserted elsewhere.\n";
	cout << "    If you want the profile earlier in the list you will need to start a new walk-through.\n";
	cout << "5 - Advance to the next profile.\n";
	cout << "6 - Return to main menu.\n";

	cin >> ans;
    return ans;
}