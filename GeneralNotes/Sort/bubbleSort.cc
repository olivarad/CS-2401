/*
bubble Sort (O = n^2)

check two adjacent indecies and swaps if not in order

You can also ignore checking the last index + itterattions index every time 

*/

#include <iostream>

using namespace std;

int main(){
    int arr[5];
    int temp;
    bool done = false;
    int i;
    int itterations = 0;

    for(int j = 0; j < 5; j++){
        cout << arr[j] << endl;
    } 

    while(!done){
        done = true;

        //compare adjacent items
        for(i = 0; i < 4 - itterations; i++){
            if(arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                itterations ++;
                done = false;
            }
        }
    }

    for(int j = 0; j < 5; j++){
        cout << arr[j] << endl;
    }     

    return 0;
}