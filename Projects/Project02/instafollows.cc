#include "instafollows.h"

using namespace std;

InstaFollows::InstaFollows(int c){ // Default Constructor
    capacity = c; // Sets the initial capacity to c
    used = 0; // Sets the initial size of used to 0
    data = new Profile[capacity]; // Allocates memory capable of storing 5 Profiles
}

InstaFollows::~InstaFollows(){ // Deconstructor
    delete []data; // Deallocate the selected profile data 
}

InstaFollows::InstaFollows(const InstaFollows& other){ // Copy Constructor
    used = other.used; // Reinitalizes used
    capacity = other.capacity; // Reinitializes capacity

    data = new Profile[other.capacity]; // Allocates memory for the new copied data

    for(int i = 0; i < other.used; i++){ // Copies data
        data[i] = other.data[i];
    }
}

void InstaFollows::operator = (const InstaFollows& other){ // Assignment operator
    if(this == &other){ // Check for self assignment
        return;
    }
    else{
        delete []data; // Deallocate old array

        used = other.used; // Reinitalizes used
        capacity = other.capacity; // Reinitializes capacity

        data = new Profile[other.capacity]; // Allocates memory for the new copied data

        for(int i = 0; i < other.used; i++){ // Copies data
        data[i] = other.data[i];
        }
    }
}

void InstaFollows::start(){ // Sets the index of the internal itterator to the beggining of the array
    current_index = 0;
}

void InstaFollows::advance(){ // Advaces the internal itterator
    current_index++;
}

bool InstaFollows::is_item()const{ // Checks if the current index has an item stored in the array
    return (current_index < used);
}

Profile InstaFollows::current()const{ // Returns the profile being pointed to by the internal itterator
    return data[current_index];
}

void InstaFollows::remove_current(){ // Removes the profile stored in current_index and rearranges the array accordingly
    Profile temp; // Temporary profile
    for (int i = current_index; i < used; i++){ // Itterates through the array starting from the index to be removed (current_index)
        temp = data[i + 1]; // Writes the next index to the temp storage variable
        data[i] = temp; // Writes the contents of temp over to the target index
    }
    used--; // Decrements used
}

void InstaFollows::insert(const Profile& p){
    if (used == capacity){ // Not enough space
        resize();
    }

    if (current_index < capacity){ // Index is valid (passed profile is inserted at the current index after moving everything to the right)
        for (int i = used; i > current_index; i--){ // Itterates through the array backwards until all neccessary profiles have been moved forward one space
            data[i] = data[i - 1]; // Write the contents of i - 1 to i
        }
        data[current_index] = p; // Writes the contents of p to the current index
    }
    else{ // Index is invalid
        for (int i = used; i > 0; i--){ // Itterates through the array backwards until all neccessary profiles have been moved forward one space
            data[i] = data[i - 1]; // Write the contents of i - 1 to i
        }
        data[0] = p; // Writes the contents of p to the first index in the array
    }
    used++;
}

void InstaFollows::attach(const Profile& p){ // If the index is valid, the data will be attached to the index after current after moving the neccesarry indecies, if it is not then it is placed at the end of the array
    if (used == (capacity - 1)){ // Not enough space
        resize();
    }

    if (current_index < capacity){ // Index is valid, data is moved to make space and the item is placed one index after current_index
        for (int i = used; i > current_index; i--){ // Itterates through the array backwards until all neccessary profiles have been moved forward one space
            data[i + 1] = data[i]; // Write the contents of i to the index after i
        }
        data[current_index + 1] = p; // Writes the contents of p to the current index plus one space
    }
    else{ // Invalid Index
        data[used] = p; // Writes the contents of p to the end of the array (This is the reason i have 3 submissions even though I originally had it right)
    }
    used++;
}

void InstaFollows::show_all(std::ostream& outs)const{ // Displays all profile data stored
    for(int i = 0; i < used; i++){
        data[i].output(outs);
    }
}

void InstaFollows::bday_sort(){ // Insertion style sort
    Profile temp;
    for (int i = 1; i < used; i++){
        temp = data[i];

        int j = i;
        while (j > 0 && data[j-1].get_bday() > temp.get_bday()){
            data[j] = data[j - 1];
            j--;
        }

        data[j] = temp;
    }
}

Profile InstaFollows::find_profile(const std::string& name)const{ // Returns the first profile containing the specified name
    for (int i = 0; i < used; i++){
        if (data[i].get_name() == name){
            return data[i];
        }
    }
    return Profile(); // Null Profile to show that it failed
}

bool InstaFollows::is_profile(const Profile& p) const{ // Returns true if the passed profile exsists
    for (int i = 0; i < used; i++){
        if (data[i] == p){
            return 1;
        }
    }
    return 0;
}

void InstaFollows::load(std::istream& ins){ // ins only makes sense as an fstream
    while(!ins.eof()){ // Runs until the end of the input file
        if (used == capacity){ // Not enough space
        resize();
        }

		data[used].input(ins); // Populates the profile entry
		used ++; // Itterates used
	}
	used--; // Decrements used to ignore the eof that previously created an extra blank profile entry 
}

void InstaFollows::save(std::ostream& outs)const{ // outs only makes sense as an fstream
    for (int i = 0; i < used; i++){
            data[i].output(outs);
    }
}

void InstaFollows::resize(){
    Profile temp[capacity + 5]; // Automatically allocated array for temporary storage
    
    for (int i = 0; i < capacity; i ++){ // itterates throught the entire array
        temp[i] = data[i]; // writes the array to the temporary stoarge variable
    }

    delete []data; // deallocates the data array

    data = new Profile[capacity + 5]; // Allocates memory

    for (int i = 0; i < capacity; i ++){ // itterates throught the entire array
        data[i] = temp[i]; // writes the array to the temporary stoarge variable
    }

    capacity += 5; // Add 5 to capacity
}