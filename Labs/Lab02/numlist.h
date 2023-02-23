#ifndef NUMLIST_H
#define NUMLIST_H
#include <iostream>
#include <cstdlib>
#include <cmath>

class NumList{
    public:
		static const size_t CAPACITY = 100;
		
		/**
		 * @brief Construct a new NumList object
		 * @pre none
		 * @post used is initialized to zero
		 * 
		 */
		NumList();

		/**
		 * @brief Add a new number to the end of the list
		 * @pre none
		 * @post num is placed at the end of the list, if there is sufficient capacity
		 * 
		 * @param num - the number being added
		 */
		void insert(int num);

		/**
		 * @brief Get the number of elements in the list
		 * 
		 * @return size_t - the number of elements in the list
		 */
		size_t size()const {return used;}

		/**
		 * @brief Load data from a file into the array
		 * @pre ins is an input stream that was successfully connected to an open file
		 * @post the data from the file is loaded into the array
		 * 
		 * @param ins - the stream to read data from
		 */
		void load_from_file(std::istream& ins);

		/**
		 * @brief Save all of the numbers being stored in the object to a file
		 * @pre outs is an output stream that was successfully connected to an open file
		 * @post the numbers from the object are written to the file
		 * 
		 * @param outs - the stream to write to
		 */
		void save_to_file(std::ostream& outs);

		/**
		 * @brief Sort the numbers in the array using a bubble sort
		 * @pre none
		 * @post the number in the array are in sorted order
		 * 
		 */
		void i_sort();

		/**
		 * @brief Get the number at the spot given by index
		 * @pre the array has a number at the spot given by index
		 * @post the value at position index is returned
		 * 
		 * @param index - the position in the array that you want to see the value for
		 * @return int - the value at position index
		 */
		int get_item(size_t index)const;

		/**
		 * @brief Show all the numbers being stored in the array.
		 * 
		 */
		void see_all()const;

    private:
		int data[CAPACITY];
		size_t used;
};

#endif