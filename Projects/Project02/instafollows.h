/*************************************************************************
   This class is a container that holds objects of the class Profile.
   It uses an internal iterator to give the application the ability to
   order the container as well as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.

	 Patricia Lindner	Spring 2023		Ohio University EECS
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "profile.h"
#ifndef INSTAF_H
#define INSTAF_H

class InstaFollows{
    public:
        InstaFollows(int c = 5); // Default Constructor

        //The functions known as the Big 3
        ~InstaFollows(); // Deconstructor
        InstaFollows(const InstaFollows& other);
        void operator = (const InstaFollows& other);

        // Functions for the internal iterator
        void start();
        void advance();
        bool is_item()const;
        Profile current()const;
        void remove_current();
        void insert(const Profile& p);
        void attach(const Profile& p);
        
        void show_all(std::ostream& outs)const;
        void bday_sort();
        Profile find_profile(const std::string& name)const;
        bool is_profile(const Profile& p) const;

        void load(std::istream& ins);
        void save(std::ostream& outs)const;

    private:
        Profile *data;
        int used;
        int capacity;
        int current_index;

        void resize(); // increases the capacity of the container by 5
};

#endif