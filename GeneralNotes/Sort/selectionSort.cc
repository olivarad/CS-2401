/*
Selection Sort (O = n^2)

Find target, then swap indecies
Do not recheck the sorted porion of data
Do not check the last index in the last run

*/

#include <iostream>

using namespace std;

int main(){
    int arr[5];
    int temp;
    int smallsp;

    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }

    // Keep track of position
    for(int i = 0; i < 4; i++){
        smallsp = i;

        //Check remaining data
        for(int j = i + 1; j < 5; j++){
            if(arr[j] < arr[smallsp]){
                smallsp = j;
            }
        }

        if(arr[i] != arr[smallsp]){
            temp = arr[i];
            arr[i] = arr[smallsp];
            arr[smallsp] = temp;
        }
    }

    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }    

    return 0;
}