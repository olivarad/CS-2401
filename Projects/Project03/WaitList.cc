/**
 * @file WaitList.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2023-02-24
 */

#include "WaitList.h"

using namespace std;

WaitList::~WaitList(){ // Deconstructor

}

WaitList::WaitList(const WaitList& other){ // Copy constructor

}

void WaitList::operator = (const WaitList& other){ // Assignment operator

}

void WaitList::add(Appointment ap){ // Adds an appointment to the list (list must be reordered after this to reflect waitlist priority)

}

void WaitList::display(std::ostream& outs)const{ // Output the list data

}

void WaitList::remove(std::string patientname){ // Removes an appointment from the list (requires changing links but not reordering)

}

unsigned int WaitList::waiting(){ // Returns an integer value of the number of people waiting
    unsigned int count = 0; // Initalizes the count of patients to 0

    return count; // Returns the number of waiting people
}

unsigned int WaitList::longest_wait(){ // Returns the longest wait in minutes (minutes of waiting for the person at the head of the list)
    unsigned int LongestWait = 0; // initializes the longest wait to 0

    return LongestWait; // Returns the longest wait in minutes
}

unsigned int WaitList::average_wait(){ // Returns the average wait in minutes
    unsigned int AverageWait = 0; // Initializes the average wait to 0
    unsigned int TotalWait = 0; // Initializes the total wait to 0
    unsigned int count = waiting(); // Calls the waiting function to find out how many patients are in the wait list

    return AverageWait; // Returns the average wait in minutes
}

unsigned int WaitList::oldest(){ // Returns the oldest patients age in years
    unsigned int oldest = 0; // Age in years of the oldest patient

    return oldest; // Returns the age of the oldest patient in years
}

unsigned int WaitList::youngest(){ // Returns the youngest patients age in years
    unsigned int youngest = 0; // Age in years of the youngest patient

    return youngest; // Returns the age of the youngest patient in years
}

unsigned int WaitList::average_age(){ // Returns the average age of all patients in years
    unsigned int average = 0; // Average age in years

    return average; // Returns the average of all patients age in years
}

void WaitList::load(std::istream& ins){ // Loads the WaitList in from a file

}

void WaitList::save(std::ostream& outs){ // Saves the contents of the WaitList to a specified outstream

}