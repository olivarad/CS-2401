/*************************************************************************
	The implementation file for the date class including the
	implementation of overloaded insertion and extraction and
	comparison operators.
  
	John Dolan			    September 2005    OHIO UNIVERSITY SCHOOL OF EECS
  Patricia Lindner    October 2021
*************************************************************************/
#include <iomanip>
#include <ctime>
#include "date_time.h"

using namespace std;

// default constructor
Date::Date(){
	day = month = year = 1;
  // permissable days for each month are loaded into an array
	daysallowed[0] = 0;
  daysallowed[1] = 31;
  daysallowed[2] = 29;
  daysallowed[3] = 31;
  daysallowed[4] = 30;
  daysallowed[5] = 31;
  daysallowed[6] = 30;
  daysallowed[7] = 31;
  daysallowed[8] = 31;
  daysallowed[9] = 30;
  daysallowed[10] = 31;
  daysallowed[11] = 30;
  daysallowed[12] = 31;
}

// constructor that takes three arguments
Date::Date(int d, int m, int y):day(d),month(m),year(y)
{
  // permissable days for each month are loaded into an array
  daysallowed[0] = 0;
  daysallowed[1] = 31;
  daysallowed[2] = 29;
  daysallowed[3] = 31;
  daysallowed[4] = 30;
  daysallowed[5] = 31;
  daysallowed[6] = 30;
  daysallowed[7] = 31;
  daysallowed[8] = 31;
  daysallowed[9] = 30;
  daysallowed[10] = 31;
  daysallowed[11] = 30;
  daysallowed[12] = 31;
}

// output operator, overloaded as a friend function
ostream& operator <<(ostream& outs, Date d){
  outs << d.month << '/' << d.day << '/' << d.year;
  return outs;
}

// input operator, overloaded as a friend
istream& operator >>(istream& ins, Date& d){
  string junk;

  ins >> d.month;
  // if an invalid month is detected throw a bad_month
  if(d.month < 1 || d.month > 12){
		getline(ins,junk); // eat the rest of the line
		throw (bad_month(d.month));
	}

  // if the read has failed because of eof exit funtion
  if(ins.eof()) return ins;

  if(ins.peek() == '/') ins.ignore();
  ins >> d.day;

  // if an invalid day is detected throw a bad_day
	if(d.day < 1  || d.day > d.daysallowed[d.month]){
		getline(ins, junk); // eat the rest of the line
		throw (bad_day(d.month, d.day));
	}
  if(ins.eof()) return ins;
  if(ins.peek() == '/') ins.ignore();

  ins >> d.year;

  return ins;
}

// return whether or not d1 is greater than d2
bool Date::operator > (const Date& d2)const{
  if(year != d2.year)
	  return (year > d2.year);
	else if(month != d2.month)
	  return(month > d2.month);
 	else
	  return (day > d2.day);
}

// return whether or not d1 is less than d2
bool Date::operator < (const Date& d2)const{
  if(year != d2.year)
    return (year < d2.year);
  else if(month != d2.month)
    return(month < d2.month);
  else
    return (day < d2.day);
}

// return whether or not d1 equals d2
bool Date::operator == (const Date& d2)const{
	return(year == d2.year && month == d2.month && day == d2.day);
}

// return whether or not d1 is not equal to d2
bool Date::operator != (const Date& d2)const{
  return(!(year == d2.year && month == d2.month && day == d2.day));

}

// return whether or not d1 is less than or equal to d2
bool Date::operator <= (const Date& d2)const{
	return (*this == d2 || *this < d2);
}

// return whether or not d1 is greater than or equal to d2
bool Date::operator >= (const Date& d2)const{
  return (*this == d2 || *this > d2);
}

DateTime::DateTime(){
  hour = 12;
  minute = 0;
}

/* When passed value is current date, returns age of member date */
int Date::age(const Date& tday)const{
  if(month < tday.month)
	  return tday.year - year;
  else if(month == tday.month && day <= tday.day)
	  return tday.year - year;
  else
	  return tday.year - year - 1;
}

void Date::make_today(){
  tm* timeptr;
  time_t timestruct;
  time(&timestruct);
  timeptr = localtime(&timestruct);
  month = timeptr -> tm_mon + 1;
  day = timeptr -> tm_mday;
  year = timeptr -> tm_year + 1900;
}

unsigned Date::minutes_since_1970()const{
  unsigned year_minutes = (year - 1970) * 365.25 * 24 * 60;
  unsigned month_minutes = 0;
  unsigned day_minutes = (day - 1) * 24 * 60;
  for(int i = 1; i < month; i++){
	  month_minutes += daysallowed[i] * 24 * 60;
  }
  if(month > 2 && year % 4 != 0)    // correction for non-leap years
	  month_minutes -= (24*60);
  return year_minutes + month_minutes + day_minutes;
}
/****************************************************************
	Functions implementations for the DateTime class.
**************************************************************/

bool DateTime::operator < (const DateTime& dt2)const{
  if(datepart != dt2.datepart)
	  return datepart < dt2.datepart;
  else if (hour != dt2.hour)
	  return hour < dt2.hour;
  else
	  return minute < dt2.minute;
}

bool DateTime::operator > (const DateTime& dt2)const{
  if(datepart != dt2.datepart)
	  return datepart > dt2.datepart;
  else if (hour != dt2.hour)
	  return hour > dt2.hour;
  else
	  return minute > dt2.minute;
}

bool DateTime::operator == (const DateTime& dt2)const{
	return(datepart == dt2.datepart && hour == dt2.hour && minute == dt2.minute);
}

bool DateTime::operator != (const DateTime& dt2)const{
	return(datepart != dt2.datepart || hour != dt2.hour || minute != dt2.minute);
}

void DateTime::input(istream& ins){
	char junk;
  ins >> datepart;
	if(&ins == &cin)
		cout << "Enter time in the form h:mm \n";
  ins >> hour >> junk >> minute;
}

void DateTime::output(ostream& outs)const{
  if(&outs == &cout){
    outs << datepart << " at " << hour << ':' << setw(2) << setfill('0') << minute << endl;
  }
  else{
    outs << datepart << endl;
    outs << hour << ':' << setw(2) << setfill('0') << minute << endl;
  }
}

unsigned DateTime::minutes_since_1970()const{
	unsigned total_minutes;
	total_minutes = datepart.minutes_since_1970() + (hour*60) + minute - (12*60);
	return total_minutes;
}

void DateTime::make_now(){
  tm* timeptr;
  time_t timestruct;
  time(&timestruct);
  timeptr = localtime(&timestruct);
  datepart = Date(timeptr -> tm_mday, timeptr -> tm_mon + 1, timeptr -> tm_year + 1900);
  hour = timeptr -> tm_hour;
  minute = timeptr -> tm_min;
}