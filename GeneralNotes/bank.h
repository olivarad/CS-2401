#include <iostream>
#include <string>

#ifndef BANK_H
#define BANK_H

namespace olivia
{
    class bankacct
    {
        public:
            // Constructor
            Bankacct(std::string o = "N/A", double bal = 0.0, double ir = 0.0); 

            // accessors
            std::string getOwnerid()const{return ownerid;}
            double getBalance()const{return balance;}
            double getIntrestRate()const{return intrestRate;}

            //mutator
            void setOwnerid(std::string o){ownerid = o;}

            // I/O
            void input(std::istream& ins);
            void output(std::ostream& outs)const;

            //Operators
            //friend Bankacct operator +(const bankacct& b1, const bankacct& b2);

            Bankacct operator + (const bankacct b2); // Member instread of a friend

        private:
            std::string ownerid; // Ownder ID
            double balance; // Balance
            double intrestRate; // Intrest rate
    } // End of Bankacct class

    std::istream& operator >> (std::istream& ins, Bankacct& b1);
    std::ostream& operator << (std::ostream& outs, const Bankacct&  b1);

} // End of custom namespace

#endif