/*
static - Memory is allocated before the program loads and the memory lasts for the entire duration of the program

Dynamic Memory - Memory is created when we manually allocate it and lasts until we deallocate it, the end of the program, or it crashes

pointers - A variable that stores an address

Memory addresses in hexadecimal (0x####)

*/
#include <iostream>
using namespace std;

int main()
{
    int x = 16;
    cout << x;
    cout << &x;

    // Make a pointer to an integer
    int* pointer; // Pointer is stored in memory
    pointer = &x; // Pointer also stores an addres other than its own now
    cout << pointer;
    cout << &pointer;
    cout << *pointer; // Dereferencing (data stored in the pointers stored address)

    int* p;
    p = new int; // Allocates a chunk of memory big enough to store the passed type and stores it to p

    *p = 34; // Changes the value of the stored variable
    delete p; // Deallocates the memory
    p = new int;

    // p = 34 - Changes the value of the stored memory address


    // Memory leaks
    /*
    new int; - Can't be deallocated without storing the address

    Do not reuse a pointer without deallocating beforehand
    p = new int;
    p = new int;
    */

    

    return 0;
}
