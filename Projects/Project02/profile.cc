#include "profile.h"

using namespace std;

Profile::Profile(std::string n, Date d){ // Default constructor
    name = n;
    bday = d;    
}



std::string Profile::get_name()const{ // Returns the username of a profile
    return name;
}

Date Profile::get_bday()const{ // Returns the birthday of a profile
    return bday;
}

bool Profile::operator == (const Profile& other)const{ // Checks if two profiles are the same
    if (name == other.name && bday == other.bday){
        return 1;
    }
    else{
        return 0;
    }
}

bool Profile::operator != (const Profile& other)const{ // Checks if two profiles are different
    if (name == other.name && bday == other.bday){
        return 0;
    }
    else{
        return 1;
    }
}

void Profile::input(std::istream& ins){ // Inputs profile data to the program
    if (&ins != &cin) // ins is a file stream
    {
        ins >> name;
        ins >> bday;
        ins.ignore();
    }
    else{ // ins is cin
        cout << "Please provide an account username: "; // Prompt for a username
		ins >> name;
		cout << "Please provide an account birthday: "; // Prompt for a birthday
		ins >> bday;
        ins.ignore();
    }
}

void Profile::output(std::ostream& outs)const{ // Outputs profile data
    if (&outs == &cout){ // outs is cout
        outs << "Username: " << name << endl; 
        outs << "Birthday: " << bday << endl;
    }
    else{ // outs is a file stream
        outs << name << endl;
        outs << bday << endl;
    }
}

std::istream& operator >> (std::istream& ins, Profile& p){ // Overloaded extraction operator
    p.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Profile& p){ // Overloaded output operator
    p.output(outs);
    return outs;
}