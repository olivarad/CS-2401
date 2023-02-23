/*************************************************************************
   This is the header file for a class called Profile. It holds some Profile
   information about a single Instagram profile, just their name and 
   birthday. It uses a class called Date for the storage of the birthday. 
   The member functions are just accessors and input/output functions.

	   Patricia Lindner	    Spring 2023		Ohio University
*************************************************************************/

#include <iostream>
#include <string>
#include "date.h"
#ifndef PROFILE_H
#define PROFILE_H

class Profile{
    public:
		Profile(std::string n = "N/A", Date d = Date());
		std::string get_name()const;
		Date get_bday()const;
		bool operator == (const Profile& other)const;
		bool operator != (const Profile& other)const;
		void input(std::istream& ins);
		void output(std::ostream& outs)const;
    private:
		std::string name;
		Date bday;
};

std::istream& operator >> (std::istream& ins, Profile& p);
std::ostream& operator << (std::ostream& outs, const Profile& p);

#endif