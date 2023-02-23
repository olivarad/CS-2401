/**
 * @file main.cc
 * @author Olivia Radecki (gr982220@ohio.edu))
 * @date 2023-01-23
 */

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    Rectangle r1(3, 2);
    Rectangle r2(2, 2);
    Rectangle r3;
    int scalar;
    cout << "Please enter a integer scalar: ";
    cin >> scalar;
    //r1.input(cin);
    //r2.input(cin);

    cout << "r1 length: " << r1.get_length() << endl;
    cout << "r1 width: " << r1.get_width() << endl;
    cout << "r1 area: " << r1.get_area() << endl;

    cout << "r2 length: " << r2.get_length() << endl;
    cout << "r2 width: " << r2.get_width() << endl;
    cout << "r2 area: " << r2.get_area() << endl;

    r3 = r1 + r2;
    r3.output(cout);

    r3 = r3 - r2;
    r3.output(cout);

    r3 = r3 * scalar;
    r3.output(cout);

    r3 = r3 / scalar;
    r3.output(cout);

    cout << "r1 == r2: " << (r1 == r2) << endl; 
    cout << "r1 < r2: " << (r1 < r2) << endl;
    cout << "r1 > r2: " << (r1 > r2) << endl;

    return 0;
}