/*************************************************************************
    This is the header file for a plantNursery class. It holds the information 
	for an array of plants. The data tracked is the name, the color , and the quantity.

	Olivia Radecki	Ohio University EECS	January 2023
*************************************************************************/

#ifndef PlantNursery
#define PlantNursey

#include "plant.h"

class PlantNursery{
    public:
        static const unsigned long int SIZE = 200; // Allowable size of plant array

        // Constructor
        PlantNursery() {used = 0;}

        void load_from_file(std::istream& ins);

        void show_all(std::ostream& outs)const;

        void add_plant(std::istream& ins);

        void remove(std::string p_name, std::string p_color);

        void change_stock_amt(std::string p_name, std::string p_color, int amt);

        void name_sort();

        void date_sort();

        void stock_sort();

        void show_plants(std::string color)const;

        void show_before(Date date)const;

        void show_colors(std::string name)const;

        double average();

        void save(std::ostream& outs)const;

    private:
        Plant plants[SIZE];
        int used;

};

#endif