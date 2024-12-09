// COMSC-210 | Lab 37 | Dan Pokhrel
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// prototypes
int sum_ascii(string str);

int main() {
    int sum = 0;

    fstream fin("data.txt");
    while(fin.good()){
        string str;
        getline(fin, str);
        sum += sum_ascii(str);
    }

    cout << sum;

    return 0;
}

int sum_ascii(string str){
    int sum = 0;
    for (char c : str)
        sum += (int)c;
    
    return sum;
}

