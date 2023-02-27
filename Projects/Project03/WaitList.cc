/**
 * @file WaitList.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2023-02-24
 */

#include "WaitList.h"
#include "appointment.h"
#include "date_time.h"

using namespace std;

WaitList::~WaitList(){ // Deconstructor
    for (node* temp = head; head != NULL; temp = head){
        head = head -> next(); // Advances head pointer
        delete temp; // Deallocates data stored behind updated head pointer
    }
}

WaitList::WaitList(const WaitList& other){ // Copy constructor (Copys an exsisting WaitList into a new waitlist)
    head = NULL; // Sets the new head equal to NULL
    for (node* cursor = other.head; cursor != NULL; cursor = cursor -> next()){ // Increments through the list to be copied from
        add(cursor -> data()); // Calls the add function with the data from other which will "reorder the lists, the input should already be reordered from load and add functions so it will not change the order, just run slightly slower"
    }
}

void WaitList::operator = (const WaitList& other){ // Assignment operator
    if(head == other.head){ // Check for self assignment
        return; // Exit function
    }
    else{
        for (node* temp = head; head != NULL; temp = head){ // Advances throught the list to be deallocated
            head = head -> next(); // Advances head pointer
            delete temp; // Deallocates data stored behind updated head pointer
        }
        delete head; // Deallocates head
        WaitList apcopy(other); // Calls the copy constructor to take care of the rest
    }
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
        newNode -> set_next(head); // Sets the pointer in newNode to the old first spot in the list
        head = newNode; // Sets the new node to be the new first element   
        reorder(); // Calls the reorder function to reorder the list
    }
}

void WaitList::display(std::ostream& outs)const{ // Output the list data
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){
        cursor -> data().output(outs); // Calls the output function in appointment
    }
}

Appointment WaitList::find(std::string patientname)const{ // Returns an appointment opject that matches the provided name
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){ // Itterates through the list
        if (cursor -> data().get_name() == patientname){ // A name match is found
            return cursor -> data(); // Returns the matching appointment
        }
    }
    return Appointment(); // Returns default appointment should one not be found
}

void WaitList::remove(std::string patientname){ // Removes an appointment from the list (requires changing links but not reordering)
    if (head -> data().get_name() == patientname){ // Edge case in which the head is to be removed
        node* temp = head; // Creates a temporary variable to prevent data loss
        head = head -> next();
        delete temp; // Deallocates removed node
        return; // Exits the function upon success
    }
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){ // Itterates through the list
        if (cursor -> next() -> data().get_name() == patientname){ // A name match is found in the next node
            node* temp = cursor -> next(); // Creates a temporary node pointer and sets it equal to the node address to be removed
            cursor -> set_next(cursor -> next() -> next());
            delete temp; // deallocates the removed node
            break; // Exits the for loop upon success
        }
    }
}

unsigned int WaitList::waiting()const{ // Returns an integer value of the number of people waiting
    unsigned int count = 0; // Unsigned int to track the count
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){ // Advances through the list and counts up all terms
            count++; // Increment list
        }
    return count; // Returns an integer value of the number of waiting patients
    }

unsigned int WaitList::longest_wait()const{ // Returns the longest wait
    return head -> data().minutes_waiting(); // Returns the longest wait in minutes
}

unsigned int WaitList::average_wait()const{ // Returns the average wait
    unsigned int TotalWait = 0; // Initializes the total wait to 0
    unsigned int count = 0; // Initializes patient count to 0
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){ // Collects data for average calculation
        TotalWait += cursor -> data().minutes_waiting(); // Adds up all the wait times
        count ++; // Increments count of patients
    }
    return TotalWait / count; // Returns the average wait
}

unsigned int WaitList::oldest()const{ // Returns the oldest patients age in years
    Date today; // Date variable to track todays date
    today.make_today(); // Sets today to todays date
    unsigned int oldest = head -> data().age(today); // Tracker to find age of oldest patient
    for (node* cursor = head -> next(); cursor != NULL; cursor = cursor -> next()){ // Itterates through the list
        if (static_cast<unsigned int>(cursor -> data().age(today)) > oldest){ // New oldest found
            oldest = cursor -> data().age(today);
        }
    }
    return oldest; // Returns the age of the oldest patient in years
}

unsigned int WaitList::youngest()const{ // Returns the youngest patients age in years
    Date today; // Date variable to track todays date
    today.make_today(); // Sets today to todays date
    unsigned int youngest = head -> data().age(today); // Tracker to find age of youngest patient
    for (node* cursor = head -> next(); cursor != NULL; cursor = cursor -> next()){ // Itterates through the list
        if (static_cast<unsigned int>(cursor -> data().age(today)) < youngest){ // New youngest found
            youngest = cursor -> data().age(today);
        }
    }
    return youngest; // Returns the age of the youngest patient in years
}

unsigned int WaitList::average_age()const{ // Returns the average age of all patients in years
    Date today; // Date variable to track todays date
    today.make_today(); // Sets today to todays date
    unsigned int TotalAge = 0; // total age in years
    unsigned int count = 0; // Initializes patient count to 0
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){ // Collects data for average calculation
        TotalAge += static_cast<unsigned int>(cursor -> data().age(today)); // Adds up all the ages
        count ++; // Increments count of patients
    }
    return TotalAge / count; // Returns the average of all patients age in years
}

void WaitList::load(std::istream& ins){ // Loads the WaitList in from a file
    Appointment ap; // Blank appointment to be written to
    while(!ins.eof() && ins.peek() != '\n'){ // Runs until the file is empty
        ins >> ap; // Aquire appointment data from ins
        add(ap); // Runs the add functino for the aquired appointment data
        while (ins.peek() == '\n'){ // Finds newlines
            ins.ignore(); // Ignores newlines
        }
    }
}

void WaitList::save(std::ostream& outs){ // Saves the contents of the WaitList to a specified outstream
    for (node* cursor = head; cursor != NULL; cursor = cursor -> next()){ // Itterates through the list
        cursor -> data().output(outs); // Calls the output function for Appointment data in the Appointment class
    }
}

void WaitList::reorder(){ // Reorders the list (to be called after adding a new node), Selction Style
    Appointment temp; // Easier to change data than order of list
    for (node* i = head; i -> next() != NULL; i = i -> next()){ // First itterator
        for (node* j = i -> next(); j != NULL; j = j -> next()){ // Second Itterator
            if (i -> data() > j -> data()){ // Compares to see if swap is neccessary
                temp = i -> data(); // Sets to prevent data loss
                i -> set_data(j -> data()); // Swaps data
                j -> set_data(temp); // Swaps data
            }
        }
    }
}