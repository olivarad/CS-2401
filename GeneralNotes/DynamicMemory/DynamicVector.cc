#include "DynamicVector.h"

Dynamic_Array::Dynamic_Array(){
    capacity = 5;
    used = 0;
    data = new int[capacity];
}

Dynamic_Array::~Dynamic_Array(){
    delete []data;
}

Dynamic_Array::Dynamic_Array(const Dynamic_Array& other){
    used = other.used;
    capacity = other.capacity;

    data = new int[capacity];

    for(int i = 0; i < other.used; i++){
        data[i] = other.data[i];
    }
}

void Dynamic_Array::operator = (const Dynamic_Array& other){
    //Check for self assignment
    if(this == &other){
        return;
    }


    delete []data; // Deallocate old array

    used = other.used;
    capacity = other.capacity;

    data = new int[other.capacity];

    for(int i = 0; i < other.used; i++){
        temp[i] = other.data[i];
    }
}

void Dynamic_Array::resize(){
    int* temp;
    temp = new int[capacity + 5];


    for(int i = 0; i < used; i++){
        temp[i] = data[i];
    }

    void Dynamic_Array::add_item(int item){
        if(used == capacity){
            resize();
        }
        data[used] = item;
        used++;
    }

/*
#include <algorith>
copy(data, data + used, temp)
*/

    delete []data;
    data = temp;
    capacity += 5;
}