#include "DoubleNode.h"
#include <cstddef>

using namespace std;

Node::Node(int d, Node* p, Node* n){ // Default Constructor
    data_field = d;
    prev_field = p;
    next_field = n;
}