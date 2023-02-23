/*************************************************************************
    This is the header file for a plant class. It holds the information 
	for a single plant, which is the name, the color , and the quantity.
	
	There are two ways of inputting into the plant object
		the input function and the >> operator.
	There are also two ways of outputting the check
		the output function and the << operator.

	Patricia Lindner	Ohio University EECS	January 2023
*************************************************************************/

#ifndef PLANT_H
#define PLANT_H

#include "date.h"
#include <iostream>
#include <string>

class Plant{
    public:
		/**
		 * @brief Construct a new Plant object
		 * 
		 * @param n - the name of the Plant
		 * @param c - the color of the Plant
		 * @param s - the number of this Plant that are in stock
		 */
		Plant(std::string n = "N/A", std::string c = "N/A", Date i = Date(), int s = 0);

		// Input and output functions
		/**
		 * @brief Allow the user to enter the information for a Plant
		 * 
		 * @param ins - the stream to read from
		 */
		void input(std::istream& ins);

		/**
		 * @brief Output the data for a Plant
		 * 
		 * @param outs - the stream to write to
		 */
		void output(std::ostream& outs)const;

		// Accessor functions
		/**
		 * @brief Get the name of the Plant
		 * 
		 * @return std::string - the name of the Plant
		 */
		std::string get_name()const {return name;}

		/**
		 * @brief Get the color of the Plant
		 * 
		 * @return * std::string - the color of the Plant
		 */
        std::string get_color()const {return color;}

		/**
		 * @brief Get the stock amount of the Plant
		 * 
		 * @return int - the number of this Plant that are in stock
		 */
		int get_stock()const {return stock;}

		/**
		 * @brief Get the date these plants came in stock
		 * 
		 * @return Date - the date these plants came in stock
		 */
		Date get_cameIn()const {return cameIn;}

		/**
		 * @brief Adjust the stock value
		 * 
		 * @param s - the value to adjust stock by
		 */
		void change_stock(int s) {stock += s;}

    private:
		std::string name;
		std::string color;
		Date cameIn;
		int stock;
};

/**
 * @brief Overloaded output operator for a Plant object
 * 
 * @param outs - the stream to write to
 * @param p - a Plant object
 * @return std::ostream& - the stream you wrote to
 */
std::ostream& operator << (std::ostream& outs, const Plant& p);

/**
 * @brief Overloaded input operator for a Plant object
 * 
 * @param ins - the stream to read from
 * @param p - the Plant object you want to set the attributes for
 * @return std::istream& - the stream you read from
 */
std::istream& operator >> (std::istream& ins, Plant& p);

#endif