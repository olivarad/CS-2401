/*************************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				
           Patricia Lindner             Spring 2023
*************************************************************************/
/**
 * @file main_lab6.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2023-02-28
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node{
     int data;
     node* next;
};


// These are the three I have implemented for you
void build_list(node*& head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

// These are the two that you are to write, as described in the instructions page.

void remove_repeats(node*& head);
void split_list(const node* original, node*& lesser, node*& greater, int split_value);



int main(){
     int start, stop;
     int split;
     node* head = NULL;
     node* lesser;
     node* greater;

     start = time(NULL);
     build_list(head);
     stop = time(NULL);
     cout << "Time to build list = " << stop - start << " seconds.\n";

     start = time(NULL);
     show_list(head);
     stop = time(NULL);
     cout << "Time to print list = " << stop - start << " seconds.\n";
     cout << "Size of the list = " << size(head) << endl;

     start = time(NULL); // Start timer
     remove_repeats(head); // Calls the remove repeats function
     stop = time(NULL); // Stop timer
     cout << "Time to remove repeats= " << stop - start << " seconds.\n"; // displays timing data

     start = time(NULL); // Start timer
     show_list(head); // Show new list
     stop = time(NULL); // Stop timer
     cout << "Time to print list = " << stop - start << " seconds.\n"; // Displays timing data
     cout << "Size of the list = " << size(head) << endl;

     cout << "Please specify a number 1 - 500 (inclusive) used to split the list: "; // Prompts for an integer for split_value
     cin >> split; // Collect split_value

     start = time(NULL); // Start timer
     split_list(head, lesser, greater, split); // Calls the split_list function
     stop = time(NULL); // Stop timer
     cout << "Time to split list = " << stop - start << " seconds.\n"; // Displays timing data


     start = time(NULL); // Start timer
     show_list(lesser); // Show new list
     stop = time(NULL); // Stop timer
     cout << "Time to print lesser list = " << stop - start << " seconds.\n"; // Displays timing data
     cout << "Size of the list = " << size(lesser) << endl;

     start = time(NULL); // Start timer
     show_list(greater); // Show new list
     stop = time(NULL); // Stop timer
     cout << "Time to print greater list = " << stop - start << " seconds.\n"; // Displays timing data
     cout << "Size of the list = " << size(greater) << endl;

     return 0;
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node*& head){
     node* cursor;

     head = new node;
     head -> data = rand() % 500 + 1;

     cursor = head;
     for(int i = 0; i < 2000; ++i){
	cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = rand() % 500 + 1;
     }
     cursor -> next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
     const node* cursor = head;

     while(cursor !=  NULL){
          cout << cursor -> data << "  ";
          cursor = cursor -> next;
     }
     cout << endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}
	return count;
}

void remove_repeats(node*& head){
     node* cursor = head; // Sets an "outer" pointer to head
     while (cursor != NULL){ // Runs through entire list
          node* itterator = cursor -> next; // Sets an "inner" pointer to the node after cursor
          node* previous = cursor; // node pointer to track the node before itterator
          while (itterator != NULL){ // Runs through entire list
               if (cursor -> data == itterator -> data){ // Data match
                    itterator = itterator -> next; // "Increment itterator"
                    delete previous -> next; // deallocates the matched node
                    previous -> next = itterator; // Recconects the list
               }
               else{
                    itterator = itterator -> next; // Itterator still needs to be updated
                    previous = previous -> next; // Updates previous
               }
          }
          cursor = cursor -> next; // Update condition for cursor
     }
}

void split_list(const node* original, node*& lesser, node*& greater, int split_value){
     node* lesser_cursor = lesser = NULL; // Cursor for lesser
     node* greater_cursor = greater = NULL; // Cursor for greater
     if (original -> data < split_value){ // Item belongs in lesser list (Original can only exsist at the begining of the list so we do not need to check this)
          lesser = new node; // Creates a new node and points to it
          lesser -> data = original -> data; // Populates lesser data
          lesser -> next = NULL; // Makes the new node point to NULL
          lesser_cursor = lesser; // Points the appropriate cursor to the head of the list
     }
     else if (original -> data > split_value){// Item belongs in greater list (Original can only exsist at the begining of the list so we do not need to check this)
          greater = new node; // Creates a new node and points to it
          greater -> data = original -> data; // Populates greater data
          greater -> next = NULL; // Makes the new node point to NULL
          greater_cursor = greater; // Points the appropriate cursor to the head of the list
     }
     for (node* cursor = original -> next; cursor != NULL; cursor = cursor -> next){ // Runs through the orignal list
          if (cursor -> data < split_value){ // Data belongs in lesser
               if (lesser_cursor == NULL){ // Begining of lesser_list
                    lesser = new node; // Creates a new node and points to it
                    lesser -> data = cursor -> data; // Populates lesser data
                    lesser -> next = NULL; // Makes the new node point to NULL
                    lesser_cursor = lesser; // Points the appropriate cursor to the head of the list
               }
               else{ // Not the lists beggining
                    lesser_cursor -> next = new node; // Creates a new node at the end of the list
                    lesser_cursor = lesser_cursor -> next; // Advances cursor
                    lesser_cursor -> data = cursor -> data; // Inputs the data to the new node
                    lesser_cursor -> next = NULL; // Makes the new node point to NUILL indicating that it is the last node in the list
               }
          }
          if (cursor -> data > split_value){ // Data belongs in greater
               if (greater_cursor == NULL){ // Begining of greater_list
                    greater = new node; // Creates a new node and points to it
                    greater -> data = cursor -> data; // Populates greater data
                    greater -> next = NULL; // Makes the new node point to NULL
                    greater_cursor = greater; // Points the appropriate cursor to the head of the list
               }
               else{ // Not the lists beggining
                    greater_cursor -> next = new node; // Creates a new node at the end of the list
                    greater_cursor = greater_cursor -> next; // Advances cursor
                    greater_cursor -> data = cursor -> data; // Inputs the data to the new node
                    greater_cursor -> next = NULL; // Makes the new node point to NUILL indicating that it is the last node in the list
               }
          }
     }
}