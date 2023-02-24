/**
 * @file WaitList.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2023-02-24
 */

#include "WaitList.h"
#include "appointment.h"

using namespace std;

WaitList::~WaitList(){ // Deconstructor
    for (node* temp = head; head != NULL; temp = head){
        head = head -> next(); // Advances head pointer
        delete temp; // Deallocates data stored behind updated head pointer
    }
}

WaitList::WaitList(const WaitList& other){ // Copy constructor

}

void WaitList::operator = (const WaitList& other){ // Assignment operator

}

void WaitList::add(Appointment ap){ // Adds an appointment to the list (list must be reordered after this to reflect waitlist priority)
    if(head == NULL){ // Empty List
        head = new node; // Creates a new node and points to it with head
        head -> set_data(ap); // Inputs the appointment data to the new node
        head -> set_next(NULL); // Makes the new node point to null indicating that it is the last node in the list
    }
    else{ // Adds a new node to the first spot in the list because reordering is required anyways
        node* newNode = new node; // Creates a node pointer and points it to a new node
        newNode -> set_data(ap); // Inputs the appointment data to the new node
        newNode -> set_next(head); // Makes the new node point to the head of the list
        head -> set_next(newNode); // Sets the head to point to the address of the new node   
        
        //Unoptimized code
        /*
        for (temp = head; temp -> next() != NULL; temp = temp -> next()) // Advances pointer to the last node in the list
        temp -> set_next(new node); // Creates a new node and points to it
        temp = temp -> next(); // Advances the pointer to the recently added node
        head -> set_data(ap); // Inputs the appointment data to the new node
        head -> set_next(NULL); // Makes the new node point to null indicating that it is the last node in the list
        */
    }
    //reorder(); // Calls the reorder function to reorder the list
}

void WaitList::display(std::ostream& outs)const{ // Output the list data
    for (node* temp = head; temp != NULL; temp = temp -> next()){
        temp -> data().output(outs); // Calls the output function in appointment
    }
}

Appointment WaitList::find(std::string patientname)const{ // Returns an appointment opject that matches the provided name
    return Appointment(); // Returns default appointment should one not be found
}

void WaitList::remove(std::string patientname){ // Removes an appointment from the list (requires changing links but not reordering)

}

unsigned int WaitList::waiting()const{ // Returns an integer value of the number of people waiting
    unsigned int count = 0; // Initalizes the count of patients to 0

    return count; // Returns the number of waiting people
}

unsigned int WaitList::longest_wait()const{ // Returns the longest wait in minutes (minutes of waiting for the person at the head of the list)
    unsigned int LongestWait = 0; // initializes the longest wait to 0

    return LongestWait; // Returns the longest wait in minutes
}

unsigned int WaitList::average_wait()const{ // Returns the average wait in minutes
    unsigned int AverageWait = 0; // Initializes the average wait to 0
    unsigned int TotalWait = 0; // Initializes the total wait to 0
    unsigned int count = waiting(); // Calls the waiting function to find out how many patients are in the wait list

    return AverageWait; // Returns the average wait in minutes
}

unsigned int WaitList::oldest()const{ // Returns the oldest patients age in years
    unsigned int oldest = 0; // Age in years of the oldest patient

    return oldest; // Returns the age of the oldest patient in years
}

unsigned int WaitList::youngest()const{ // Returns the youngest patients age in years
    unsigned int youngest = 0; // Age in years of the youngest patient

    return youngest; // Returns the age of the youngest patient in years
}

unsigned int WaitList::average_age()const{ // Returns the average age of all patients in years
    unsigned int average = 0; // Average age in years

    return average; // Returns the average of all patients age in years
}

void WaitList::load(std::istream& ins){ // Loads the WaitList in from a file

}

void WaitList::save(std::ostream& outs){ // Saves the contents of the WaitList to a specified outstream

}