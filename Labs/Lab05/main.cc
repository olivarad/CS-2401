#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main(){
    Lilist L1, L2;
    string target;
    L1.add("Elizabeth");
    L1.add("Zachary");
    L1.add("Clay");
    L1.add("Lainie");
    L1.add("Izaak");
    L1.add("Andrew");
    cout << "Now showing list One: \n";
    L1.show();
    cout << "Please enter a target name: ";
    cin >> target;
    if (L1.search(target) != NULL){
        cout << "That name is stored at address: " << L1.search(target) << endl;
    }
    else{
        cout << "That name is not in the list.\n";
    }
    L1.move_front_to_back();
    L1.move_front_to_back();
    L1.show();
   return 0;
}
