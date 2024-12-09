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

    // Read file and populate hash_table
    fstream fin("data.txt");
    while(fin.good()){
        string str;
        getline(fin, str);
        int hash = get_hash_index(str);
        hash_table[hash].push_back(str);
    }

    // display first 100 entires
    int i = 0;
    for (auto pair : hash_table){
        i ++; if (i > 100) break;

        int hash = pair.first;
        list<string> value = pair.second;
        cout << hash << " : ";
        for (string str : value)
            cout << str << " ";
        cout << endl;
    }

    return 0;
}

int get_hash_index(string str){
    int sum = 0;
    for (char c : str)
        sum += (int)c;
    
    return sum % 3079;
}