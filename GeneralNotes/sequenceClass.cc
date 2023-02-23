class sequenceClass{
    public:
        static const int SIZE = 200;

        //constructor
        //accessor and mutator

        //iterator functions
        void start(){current_index = 0;} // Moves to start of the array
        void advance(){current_index++;} // Advances in the array
        int current()const {return data[current_index];} 
        bool is_item()const {return current_index < used;}

        //sequence functions
        void remove(); // Removes item at current_index (Copy each right bound item over 1 to the left, end with used--)
        void insert(const int& item); // Check if the current_index is valid, true-move everything to the right of this index one to the right, false-do this but assume the new item will be the first stored item
        void attach(const int& item); // If the index is not valid then the new item is placed at the end of the array but if it is valid it goes after an index

    private:
        int data[SIZE];
        int used;
        int current_index; // Internal Itterator

};