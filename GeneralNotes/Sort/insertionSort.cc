/*
insertion sort (O = n^2)

Reverse search of order

*/

#include <iostream>

using namespace std;

int main(){
    int arr[5];
    int temp;
/*
    for(int j = 0; j < 5; j++){
        cout << arr[j] << endl;
    } 
*/
    for(int i = 1; i < 5; i++){
        temp = arr[i];

        int j = i;
        while(j > 0 && arr[j-1] > temp){
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = temp;
    }
/*
    for(int j = 0; j < 5; j++){
        cout << arr[j] << endl;
    }     
*/
    return 0;
}