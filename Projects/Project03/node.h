/*************************************************************************
    This file is borrowed heavily from Main/Savitch "Data Structures and
    Other Object Using C++," Chapter 5. It features a node class that 
    can be used in the construction of linked lists.
    
	Patricia Lindner	February 2023
*************************************************************************/

#ifndef NODE_H
#define NODE_H
#include "appointment.h"

class node{
    public:
        // create a new type called value_type that is set to Appointment
		typedef Appointment value_type;

		/**
		 * @brief Construct a new node object
		 * 
		 * @param d - the object to set the data to, calls the default constructor for that type if no argument is passed
		 * @param l - the pointer to set the link to, NULL by default
		 */
        node(value_type d = value_type(), node *l = NULL) {data_field = d;  next_field = l;}

        /**
         * @brief Set the data object
         * 
         * @param d - the object to set data_field to
         */
		void set_data(value_type d) {data_field = d;}

        /**
         * @brief Set the next object
         * 
         * @param l - the pointer to set next_field to
         */
		void set_next(node *l) {next_field = l;}

        /**
         * @brief Return the data in this node
         * 
         * @return value_type - the data
         */
        value_type data() const {return data_field;}

        /**
         * @brief Return the next in this node
         * 
         * @return node* - the next to the next node
         */
        node* next() {return next_field;}

        /**
         * @brief Return the link in this node as a const reference (the pointer can "move" but you cannot change the values in the node pointed to by this pointer)
         * 
         * @return const node* - the link to the next node
         */
		const node* next() const {return next_field;}

    private:
		value_type data_field;
		node* next_field;
};

#endif