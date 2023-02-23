#include "numbers.h"

void Numbers::double seeAll()const{
    for int(i = 0; i < used; i++){
        cout << data[i] << " ";
    }
}

double Number::sumAll()const{
    double sum = 0;
    for(int i = 0, i < used; i++){
        sum+= data[i];
    }
    return sum;
}

void Numbers::addItem(double item){
    if(used < SIZE){
        data[used] = item;
        used++;
    }
    else{
        cout << "No remaining indexes\n";
    }
}























#include "simpleArrays.h"
bool Names::is_there(std::string target)const{
    size_t i = 0;
    while(i < used){
        if(data[i] == target){
            return true;
        }
        i++;
    }
    return false;
}

void Names::remove(std::target){
    for(size_t i = 0; i < used; i++){
        if(data[i] == target){
            
        }
    }
}