/**
 * @file part3.cc
 * @author Olivia Radecki(gr982220@ohio.edu)
 * @date 2023-02-06
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    size_t capacity = 5; // capacity variable
    size_t used = 0; // Used variable
    int* ptr; // Declare a pointer capable of stroing the adress of a double
    //ptr = new double; // Allocate memory that is able to store a double and write the address to the pointer ptr
    int* tmpptr;

    ptr = new int[capacity];
    for(size_t i = 0; i < 25; ++i){
        ptr[used] = rand(); // you will need #include <cstdlib>
        //cout << ptr[used] << " ";
        used++;
        if(used == capacity){
        tmpptr = new int[capacity + 5];

        for(size_t i = 0; i < used; i++){
            tmpptr[i] = ptr[i];
        }
        tmpptr[2] = 0;
        capacity += 5;
        delete []ptr;
        ptr = tmpptr;
        cout << "Resized\n";
        }
    }

    for(size_t i = 0; i < used; i++){
        cout << ptr[i] << endl;
    }

    delete []ptr; // Deallocates ptr to prevent a memory leak
    delete []tmpptr;
    return 0;
}