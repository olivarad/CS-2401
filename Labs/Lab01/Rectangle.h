/**
 * @file main.cc
 * @author Olivia Radecki (gr982220@ohio.edu))
 * @date 2023-01-23
 */

// Add documentation for the file and each function

#include <iostream>
    
class Rectangle
{   
  public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    //Rectangle();
    Rectangle(double l = 1.0, double w = 1.0);   

    // Member functions
    void input(std::istream& ins);            
    void output(std::ostream& outs);

    double get_length()const {return length;}
    double get_width()const {return width;}
    double get_area()const {return area;}


    Rectangle operator + (const Rectangle& r);

    Rectangle operator - (const Rectangle& r);

    Rectangle operator * (const int& num);

    Rectangle operator / (const int& num);

    bool operator == (const Rectangle& r);

    bool operator < (const Rectangle& r);

    bool operator > (const Rectangle& r);

    // Friend functions
    //friend Rectangle operator + (const Rectangle& r1, const Rectangle& r2);
 
    //friend Rectangle operator - (const Rectangle& r1, const Rectangle& r2);
 
    //friend Rectangle operator * (const Rectangle& r1, int num);

    //friend Rectangle operator / (const Rectangle& r1, int num);

    //friend bool operator == (const Rectangle& r1, const Rectangle& r2);

    //friend bool operator < (const Rectangle& r1, const Rectangle& r2);

    //friend bool operator > (const Rectangle& r1, const Rectangle& r2);    

    //friend std::istream& operator >> (std::istream& fin, Rectangle& r);
    
    //friend std::ostream& operator << (std::ostream& fout, const Rectangle& r);
   
  private:
      double length;  // should not be able to go < 0
      double width;   // should not be able to go < 0
      double area;
 };

 std::istream& operator >> (std::istream& fin, Rectangle& r);
 std::ostream& operator << (std::ostream& fout, Rectangle& r);