#include <iostream>
#include <string>

#ifndef LIST_H
#define LIST_H

struct Node{
    std::string data;
    Node* next;
};

class Lilist{
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string target);
        void move_front_to_back();

    private:
        Node *head;

};

void Lilist::add(std::string item){
    Node* temp;
    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> next = NULL;
    }
    else{
        for (temp = head; temp -> next != NULL; temp = temp -> next); // Advances pointer to the last node in the list
        temp -> next = new Node;
        temp = temp -> next;
        temp -> data = item;
        temp -> next = NULL;
    }
}

void Lilist::show(){
    for (Node* temp = head; temp != NULL; temp = temp -> next){
        std::cout << temp -> data << " ";
    }
    std::cout << std::endl;
}

Node* Lilist::search(std::string target){
    for (Node* cursor = head; cursor != NULL; cursor = cursor -> next){ // Creates a cursor to run through the linked list
        if (cursor -> data == target){ // Checks for equivalance between the data stored in the address of the cursor and the passed in target data
            return cursor; // returns the address of the cursor
        }
    }
    return NULL; // If no match exsist Null is returned
}

void Lilist::move_front_to_back(){
    Node* pointer = head; // New pointer to store the head
    head = head -> next; // Move head to the second item in the list
    for (Node* cursor = pointer; cursor != NULL; cursor = cursor -> next){ //Run through the list
        if (cursor -> next == NULL){ // Last item in list
            cursor -> next = new Node; // Makes a new node and adds it to the list
            cursor = cursor -> next; // moves the cursor to the new node
            cursor -> data = pointer -> data; // inputs the data
            cursor -> next = NULL; // Updates the new node to point to NULL indicating that this is the last item in the list
            delete pointer; // Deallocation of the orignal first item so that there will not be two of them where one is never used again
        }
    }

}

#endif