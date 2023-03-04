#ifndef LIST_H
#define LIST_H

#include "DoubleNode.h"
#include <cstddef>
#include <iostream>
#include <fstream>

class List{
    public:
        List(){head = tail = NULL;} // Default Constructor
        //~List(); // Deconstructor
        List(const List& other); // Copy constructor
        void operator = (const List& other); // Assignment operator

        void add(int i);
        void display(std::ostream& outs)const;
        void remove(int i);
        unsigned int list_length()const;
        unsigned int greatest()const;
        unsigned int least()const;
        unsigned int average()const;
        void load(std::istream& ins);
        void save(std::ostream& outs);
        void reorder();

    private:
        Node* head;
        Node* tail;
};

#endif