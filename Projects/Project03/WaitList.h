/**
 * @file WaitList.h
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2023-02-27
 */


#ifndef WAISTLIST_H
#define WAISTLIST_H

#include "appointment.h"
#include "date_time.h"
#include "node.h"

class WaitList{
    public:
    	/**
		 * @brief Default Constructor
		 * 
		 * @return A constructed Waitlist
		 */
        WaitList(){head = NULL;}
        ~WaitList(); // Deconstructor
        /**
		 * @brief Copy Constructor
		 * 
		 * @param other - Waitlist to copy from
		 * @return A new Waitlist with copied data_types
		 */
        WaitList(const WaitList& other);
        /**
		 * @brief Assignment Operator
		 * 
		 * @param other - Waitlist to get data from
		 * @return A resized Waitlist with data_types from other
		 */
        void operator = (const WaitList& other);

        /**
		 * @brief add
		 * 
		 * @param ap - Appointment to add into a waitlist
		 * @return void
		 */
        void add(Appointment ap); // Adds an appointment to the list (list must be reordered after this to reflect waitlist priority)
        /**
		 * @brief display
		 * 
		 * @param outs - Outstream
		 * @return void
		 */
        void display(std::ostream& outs)const; // Output the list data
        /**
		 * @brief find
		 * 
		 * @param patientname - Name of a patient in the waitlist
		 * @return Appointment with name match
		 */
        Appointment find(std::string patientname)const; // Returns an appointment opject that matches the provided name
        /**
		 * @brief remove
		 * 
		 * @param patientname - Name of a patient in the waitlist
		 * @return void
		 */
        void remove(std::string patientname); // Removes an appointment from the list (requires changing links but not reordering)
        /**
		 * @brief Waiting
		 * 
		 * @return number of appointments in the waitlist as an unsigned integer
		 */
        unsigned int waiting()const; // Returns an integer value of the number of people waiting
        /**
		 * @brief longest_wait
		 * 
		 * @return longest appointment wait time in minutes as an unsigned integer
		 */
        unsigned int longest_wait()const; // Returns the longest wait in minutes (minutes of waiting for the person at the head of the list)
        /**
		 * @brief average_wait
		 * 
		 * @return average wait time as an unsigned integer of all appointments in the waitlist
		 */
        unsigned int average_wait()const; // Returns the average wait in minutes
        /**
		 * @brief oldest
		 * 
		 * @return age of the oldest individual in the wait list as an unsigned integer
		 */
        unsigned int oldest()const; // Returns the oldest patients age in years
        /**
		 * @brief youngest
		 * 
		 * @return youngest age in the waitlist as an unsigned integer
		 */
        unsigned int youngest()const; // Returns the youngest patients age in years
        /**
		 * @brief average_age
		 * 
		 * @return average age of all patients in the waitlist as an unsigned integer
		 */
        unsigned int average_age()const; // Returns the average age of all patients in years
        /**
		 * @brief load
		 * 
         * @param ins - An instream
		 * @return void
		 */
        void load(std::istream& ins); // Loads the WaitList in from a file
        /**
		 * @brief save
		 * 
         * @param outs - An outstream
		 * @return void
		 */
        void save(std::ostream& outs); // Saves the contents of the WaitList to a specified outstream
        /**
		 * @brief reorder
		 *
		 * @return void
		 */
        void reorder(); // Reorders the list (to be called after adding a new node)
    private:
    node* head; // Pointer to the head of the linked list
};

#endif