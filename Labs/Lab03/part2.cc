/**
 * @file part2.cc
 * @author Olivia Radecki(gr982220@ohio.edu)
 * @date 2023-02-06
 */

#include <iostream>
using namespace std;

int main(){
    double* p; // Declare a pointer capable of stroing the adress of a double
    p = new double; // Allocate memory that is able to store a double and write the address to the pointer p
    
    cout << p << endl; // Write the address that the pointer is storing to the terminal (this is not the address of the pointer but it is the adress stored by it)
    cout << &p << endl; // Adress of the pointer (not the adress stored in it)

    *p = 24.01; // Writes a new value to the double stored by the adress stored by p

    for(int i = 0; i < 10; i++){
        ++(p); // Increments the address stored by the pointer p
        cout << *p << " is stored at " << p << endl; // Outputs the value of the double and the address
    }

    delete p; // Deallocates p to prevent a memory leak
    return 0;
}