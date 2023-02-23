class Dynamic_Array{
    public:
        Dynamic_Array(); // Constructor

        ~Dynamic_Array(); // Deconstructor

        //copy constructor
        Dynamic_Array(const Dynamic_Array& other);

        // Overloaded assignment operator
        void operator = (const Dynamic_Array& other);

        void add_item(int item);
        

    private:
        int* data; // Pointer for int named data
        int used; // Used spots
        int capacity; // Total spots available

        void resize();
};