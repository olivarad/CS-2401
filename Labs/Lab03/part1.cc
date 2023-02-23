/**
 * @file part1.cc
 * @author Olivia Radecki(gr982220@ohio.edu)
 * @date 2023-02-06
 */

#include <iostream>
using namespace std;

void stars();

int main(){
    for(int i = 0; i < 6; i++){
        stars();
    }

    return 0;
}

void stars(){
    static int x = 0;
    x++;
    for(int i = 0; i < x; ++i){
        cout << '*';
    }
    cout << endl;
}