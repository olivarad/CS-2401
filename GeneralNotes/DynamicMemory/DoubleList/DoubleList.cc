#include "DoubleNode.h"
#include "DoubleList.h"

using namespace std;

void List::add(int i){
    if (head == NULL){ // Empty list
        head = tail = new Node; // Sets head and tail to the only item in the list
        head -> set_next(NULL); // Sets the next node to NULL to indicate end of list
        head -> set_prev(NULL); // Sets the previous node to NULL to indicate start of list
        head -> set_data(i); // Set the data in head to the passed in integer
    }
}