/*************************************************************************
    This is the record of a person waiting for an appointment for their
    flu vaccine. It includes the person's name, age and the date
    and time when they called in to get the appointment.
    Overloaded comparison operators compare the time they called in,
    with less than meanng that the left operand has called in earlier
    than the righ operand.

	John Dolan			
	Patricia Lindner	February 2023	OU EECS
*************************************************************************/
#include <iostream>
#include <string>
#include "date_time.h"

#ifndef APP_H
#define APP_H

class Appointment{
	public:
		/**
		 * @brief Construct a new Appointment object
		 * 
		 */
		Appointment();

		/**
		 * @brief Get the name object
		 * 
		 * @return std::string - the name of the person
		 */
		std::string get_name()const {return name;}

		/**
		 * @brief Get the bday object
		 * 
		 * @return Date - the birthday of the person
		 */
		Date get_bday()const {return bday;}

		/**
		 * @brief Get the callin object
		 * 
		 * @return DateTime - the date and time the person called in
		 */
		DateTime get_callin()const {return called;}

		/**
		 * @brief Less than operator
		 * 
		 * @param ap - Appointment to compare to
		 * @return true - this Appointment called in before ap
		 * @return false - this Appointment called in after ap
		 */
		bool operator < (const Appointment& ap)const {return called < ap.called;}

		/**
		 * @brief Greater than operator
		 * 
		 * @param ap - Appointment to compare to
		 * @return true - this Appointment called in after ap
		 * @return false - this Appointment called in before ap
		 */
		bool operator > (const Appointment& ap)const {return ap.called < called;}

		/**
		 * @brief Less than or equal to operator
		 * 
		 * @param ap - Appointment to compare to
		 * @return true - this Appointment called in at the same time or before ap
		 * @return false - this Appointment called in after ap
		 */
		bool operator <= (const Appointment& ap)const {return !(ap.called < called);}

		/**
		 * @brief Greater than or equal to operator
		 * 
		 * @param ap - Appointment to compare to
		 * @return true - this Appointment called in at the same time or after ap
		 * @return false - this Appointment called in before ap
		 */
		bool operator >= (const Appointment& ap)const {return !(called < ap.called);}

		/**
		 * @brief Not equal operator
		 * 
		 * @param ap - Appointment to compare to
		 * @return true - this Appointment did not call in at the same time as ap
		 * @return false - this Appointment called in at the same time as ap
		 */
		bool operator != (const Appointment& ap)const {return (called < ap.called || ap.called < called);}

		/**
		 * @brief Equality operator
		 * 
		 * @param ap - Appointment to compare to
		 * @return true - this Appointment called in at the same time as ap
		 * @return false - this Appointment did not call in at the same time as ap
		 */
		bool operator == (const Appointment& ap)const {return !(called < ap.called || ap.called < called);}
		
		/**
		 * @brief Determine the age of the person with this Appointment
		 * 
		 * @param tday - a "today" object (Date set to today's date)
		 * @return int - the age of the person with this Appointment
		 */
		int age(const Date& tday)const {return bday.age(tday);}

		/**
		 * @brief Return the number of minutes this person has been waiting for their appointment
		 * 
		 * @return unsigned - number of minutes this Appointment has been waiting
		 */
		unsigned minutes_waiting()const;

		/**
		 * @brief Input all the data for this Appointment
		 * 
		 * @param ins - the stream to read from
		 */
		void input(std::istream& ins);

		/**
		 * @brief Output all the data for this Appointment
		 * 
		 * @param outs - the stream to write to
		 */
		void output(std::ostream& outs)const;

	private:
		std::string name;
		Date bday;
		DateTime called;
};

/**
 * @brief Transform and output a number of minutes to the format Days: <x> Hours: <y> Minutes: <z>
 * 
 * @param m - the number of minutes to convert
 */
void convert_minutes(unsigned m);

/**
 * @brief Extraction operator
 * 
 * @param ins - the stream to read from
 * @param ap - the Appointment to input data to
 * @return std::istream& - the stream you read from
 */
std::istream& operator >> (std::istream& ins, Appointment & ap);

/**
 * @brief Insertion operator
 * 
 * @param outs - the stream to write to
 * @param ap - the Appointment for which data is being written
 * @return std::ostream& - the stream you output to
 */
std::ostream& operator << (std::ostream& outs, const Appointment& ap);

#endif