using namespace std;

int main()
{
}

class Numbers // Container Class
{
    public:
        static const int SIZE = 200; // Static Allocates memory at the begginging of the program and will not change it for the duration of runtime

        Numbers(){used = 0;}

        void addItem(double item);
        double sumAll()const;
        double seeAll()const;

    private:
        double data[SIZE];
        int used;
};
























#include <string>

#ifndef Names_H
#define Names_H
class Names{

    public:
        static const size_t SIZE = 10;
        names() {used = 0;}
        bool is_there(std::string target)const;
        void remove(std::string target);

    private:
        std::string data[SIZE];
        size_t used;

}

#endif