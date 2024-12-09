// COMSC-210 | Lab 37 | Dan Pokhrel
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// prototypes
int get_hash_index(string str);
void print_first(map<int, list<string>> &table);
void search_key(map<int, list<string>> &table);
void add_key(map<int, list<string>> &table);
void remove_key(map<int, list<string>> &table);
void modify_key(map<int, list<string>> &table);

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
        cout << hash << " : " << value.size();
        for (string str : value)
            cout << str << " ";
        cout << endl << endl;
    }

    int choice = 0;
    while (choice != 6){
        cout << "Hash Table Menu\n";
        cout << "1. Print first 100 entries.\n";
        cout << "2. Search for a key.\n";
        cout << "3. Add a key.\n";
        cout << "4. Remove a key.\n";
        cout << "5. Modify a key.\n";
        cout << "6. Exit\n";
        cout << "Choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            break;
        
        default:
            cout << "Invalid Input\n\n";
            break;
        }
    }

    return 0;
}

int get_hash_index(string str){
    int sum = 0;
    for (char c : str)
        sum += (int)c;
    
    return sum % 3078;
}

void print_first(map<int, list<string>> &table)
{
}

void search_key(map<int, list<string>> &table)
{
}

void add_key(map<int, list<string>> &table)
{
}

void remove_key(map<int, list<string>> &table)
{
}

void modify_key(map<int, list<string>> &table)
{
}
