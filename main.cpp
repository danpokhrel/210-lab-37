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
        cout << endl;

        switch (choice)
        {
        case 1:
            print_first(hash_table);
            break;
        case 2:
            search_key(hash_table);
            break;
        case 3:
            add_key(hash_table);
            break;
        case 4:
            remove_key(hash_table);
            break;
        case 5:
            modify_key(hash_table);
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
    // display first 100 entires
    int i = 0;
    for (auto pair : table){
        i ++; if (i > 100) break;

        int hash = pair.first;
        list<string> value = pair.second;
        cout << hash << " : " << value.size();
        for (string str : value)
            cout << str << " ";
        cout << endl << endl;
    }
}

void search_key(map<int, list<string>> &table)
{
    cout << "Key: ";
    string key; cin >> key;

    // if key exists
    if (table.count(get_hash_index(key))){
        cout << "Key found.\n\n";
        return;
    }

    cout << "Key not found.\n\n";
}

void add_key(map<int, list<string>> &table)
{
    cout << "Key: ";
    string key; cin >> key;

    int hash = get_hash_index(key);
    table[hash].push_back(key);

    cout << "Added key.\n\n";
}

void remove_key(map<int, list<string>> &table)
{
    cout << "Key: ";
    string key; cin >> key;

    // key doesn't exists
    if (!table.count(get_hash_index(key))){
        cout << "Key not found.\n\n";
        return;
    }

    table[get_hash_index(key)].remove(key);
    cout << "Key has been removed.\n\n";
}

void modify_key(map<int, list<string>> &table)
{
    cout << "Key: ";
    string key; cin >> key;
    cout << "New: ";
    string key2; cin >> key;

    // key doesn't exists
    if (!table.count(get_hash_index(key))){
        cout << "Key not found.\n\n";
        return;
    }

    table[get_hash_index(key)].remove(key);
    table[get_hash_index(key2)].push_back(key2);
}
