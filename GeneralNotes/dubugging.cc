/*
compilations with g++ -g option reqired
run code with gdb ./a.out

break file_name:linenumber
break file_name:function_name
if in main.cc break function_name

run
n or next to run line by line
s or step to move execution into a function
c or continue to execute until the next break point
p or peek variable_name to see the value of a variable
info local shows the value of every variable in context
where see the current line of code that youre on
q or quit to exit the dubugger
*/

#include <iostream>
using namespace std;

int main(){
    int sum;
    int n;
    int count;

    cout << "Enter a number to be averaged or negative number to quit: ";
    cin >> n;

    while (n >= 0){
        sum += n;
        count++;
        cin >> n;
    }

    cout << "The average is: " << (double) sum / n << endl;

    return 0;
}