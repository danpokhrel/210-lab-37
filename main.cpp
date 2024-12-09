// COMSC-210 | Lab 37 | Dan Pokhrel
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// prototypes
int get_hash_index(string str);

int main() {
    map<int, list<string>> hash_table;

    fstream fin("data.txt");
    while(fin.good()){
        string str;
        getline(fin, str);
        int hash = get_hash_index(str);
        hash_table[hash].push_back(str);
    }

    for (auto pair : hash_table){

    }

    return 0;
}

int get_hash_index(string str){
    int sum = 0;
    for (char c : str)
        sum += (int)c;
    
    return sum % 97;
}