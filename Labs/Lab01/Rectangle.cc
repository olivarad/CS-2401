/**
 * @file main.cc
 * @author Olivia Radecki (gr982220@ohio.edu))
 * @date 2023-01-23
 * The implementation file for the Rectangle class
 */
 
#include "Rectangle.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors
Rectangle::Rectangle(double l, double w){
	if (l >= 0){
		length = l;
	}
	else{
		length = 0.0;
	}
	if (w >= 0){
		width = w;
	}
	else{
		width = 0.0;
	}
	area = l * w;
	if (area == -0){
		area = 0;
	}
}

// Member functions

Rectangle Rectangle::operator + (const Rectangle& r){
	Rectangle tmp;
    tmp.length = length + r.length;
	tmp.width = width + r.width;
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

Rectangle Rectangle::operator - (const Rectangle& r){
	Rectangle tmp;
	if(length >= r.length){
		tmp.length = length - r.length;
	}
	else{
		tmp.length = 0;
	}

	if(width >= r.width){
		tmp.width = width - r.width;
	}
	else{
		tmp.width = 0;
	}
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

Rectangle Rectangle::operator * (const int& num){
	Rectangle tmp;
	tmp.length = length * num;
	tmp.width = width * num;
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

Rectangle Rectangle::operator / (const int& num){
	Rectangle tmp;
	tmp.length = length / num;
	tmp.width = width / num;
	tmp.area = tmp.length * tmp.width;
	return tmp;
}

bool Rectangle::operator == (const Rectangle& r){
	return length == r.length && width == r.width;
}

bool Rectangle::operator < (const Rectangle& r){
	return area < r.area;
}

bool Rectangle::operator > (const Rectangle& r){
	return area > r.area;
}

void Rectangle::input(std::istream& ins){
		cout << "Enter the length: ";
		ins >> length;
		if ( length < 0){
			length = 0;
		}
		cout << " Enter the width: ";
		ins >> width;
		if ( width < 0){
			width = 0;
		}
		area = length * width;
	/* Move the implementation code from the >> operator show below here.
	   Remember that since this function will be a member now, there will not be an r1.

	   The >> operator should now call this function.
	   Remove the friend keyword from the operator in the .h file and move the
	   function prototype to after the class declaration.
	*/
}

void Rectangle::output(ostream& outs){
    outs << "Length: " << length << endl;
	outs << "Width: " << width << endl;
	outs << "Area: " << area << endl;
}

std::ostream& operator << (ostream& outs, Rectangle& r){
	r.output(outs);
	return outs;
}

std::istream& operator >> (istream& ins, Rectangle& r){
	r.input(ins);
	return ins;
}