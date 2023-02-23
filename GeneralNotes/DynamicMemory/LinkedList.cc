struct Node{
    int data;
    Node* next;
};
Node* head; // Pointer to the beggining of the linked list
//at operator -> same as dereferencing
//head = NULL; or head = nullprt; This makes the address stored be adress 0 which is protected

head = new Node; // Allocates space for the first node and sets the stored address in the pointer to this address allocated
//The last node in the list should always point to NULL to show that its the last node
(*head).next = nullptr;
(*head).data = 1;

(*head).next = new Node; // Points to allocated memory capable of storing a new node
//(*(*head).next).next = nullptr;
head -> next -> next = nullptr;
(*(*head).next).data = 2;

void add_to_end(Node*& head, int d){
    if(head == NULL){ // Empty list
        head = new Node;
        head -> data = d;
        head -> next = NULL;
    }
    else{
        Node* cursor = head;
        while(cursor -> next != NULL){
            cursor = cursor -> next;
        }

        cursor -> next = new Node;

        cursor = cursor -> next;
        cursor -> data = d;
        cursor -> next = NULL;
    }
}

void remove(Node*& head, int target){
    if(head -> data == target){
        Node* temp = head;
        head = head -> next;
        delete tmp;
    }
    else{
        Node* previous = head;
        Node* cursor = head;

        while(cursor -> data != target){
            previous = cursor;
            cursor = cursor -> next;
        }

        previous -> next = cursor -> next;
        delete cursor;
    }
}