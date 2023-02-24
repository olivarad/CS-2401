/**
 * @file WaitList.h
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2023-02-24
 */


#ifndef WAISTLIST_H
#define WAISTLIST_H

#include "appointment.h"
#include "date_time.h"
#include "node.h"

class WaitList{
    public:
        WaitList(){head = NULL;} // Default Constructor
        ~WaitList(); // Deconstructor
        WaitList(const WaitList& other); // Copy constructor
        void operator = (const WaitList& other); // Assignment operator

        void add(Appointment ap); // Adds an appointment to the list (list must be reordered after this to reflect waitlist priority)
        void display(std::ostream& outs)const; // Output the list data
        Appointment find(std::string patientname); // Returns an appointment opject that matches the provided name
        void remove(std::string patientname); // Removes an appointment from the list (requires changing links but not reordering)
        unsigned int waiting(); // Returns an integer value of the number of people waiting
        unsigned int longest_wait(); // Returns the longest wait in minutes (minutes of waiting for the person at the head of the list)
        unsigned int average_wait(); // Returns the average wait in minutes
        unsigned int oldest(); // Returns the oldest patients age in years
        unsigned int youngest(); // Returns the youngest patients age in years
        unsigned int average_age(); // Returns the average age of all patients in years
        void load(std::istream& ins); // Loads the WaitList in from a file
        void save(std::ostream& outs); // Saves the contents of the WaitList to a specified outstream
    private:
    node* head; // Pointer to the head of the linked list
};

#endif