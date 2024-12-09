// COMSC-210 | Lab 37 | Dan Pokhrel
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// prototypes
int sum_ascii(string str);

int main() {
    cout << sum_ascii("A") << endl;
    cout << sum_ascii("5") << endl;
    cout << sum_ascii("H") << endl;
    cout << sum_ascii("?") << endl;
    cout << sum_ascii("abcdef") << endl;

    return 0;
}

int sum_ascii(string str){
    int sum = 0;
    for (char c : str)
        sum += (int)c;
    
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
