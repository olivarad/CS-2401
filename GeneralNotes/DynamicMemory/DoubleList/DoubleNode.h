#ifndef NODE_H
#define NODE_H
class Node{
    public:
        Node(int d = 0, Node* p = nullptr, Node* n = nullptr); // Default Constructor

        int data()const {return data_field;}
        Node* next()const {return next_field;}
        Node* prev()const {return prev_field;}

        void set_data(int d) {data_field = d;}
        void set_next(Node* n) {next_field = n;}
        void set_prev(Node* p) {prev_field = p;}

        void add(int d);

    private:
        int data_field;
        Node* next_field;
        Node* prev_field;

};

#endif