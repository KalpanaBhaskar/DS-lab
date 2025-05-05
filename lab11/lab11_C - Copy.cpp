#include <iostream>
#include <list>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    list<int> table[TABLE_SIZE];

public:
    int hash(int key);

    string insert(int key);
    string remove(int key);
    string search(int key);
    string display();
};

int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

string HashTable::insert(int key) {
    int index = hash(key);
    table[index].push_back(key);
    return "Inserted in chain at index " + to_string(index);
}

string HashTable::remove(int key) {
    int index = hash(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            table[index].erase(it);
            return "Deleted from index " + to_string(index);
        }
    }
    return "Key not found";
}

string HashTable::search(int key) {
    int index = hash(key);
    for (int val : table[index]) {
        if (val == key)
            return "Key found at index " + to_string(index);
    }
    return "Key not found";
}

string HashTable::display() {
    string result = "";
    for (int i = 0; i < TABLE_SIZE; i++) {
        result += to_string(i) + ": ";
        for (int val : table[i])
            result += to_string(val) + " -> ";
        result += "NULL\n";
    }
    return result;
}

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin >> key;
            cout << ht.insert(key) << endl;
        } 
        else if (choice == 2) {
            cout << "Enter key to delete: ";
            cin >> key;
            cout << ht.remove(key) << endl;
        } 
        else if (choice == 3) {
            cout << "Enter key to search: ";
            cin >> key;
            cout << ht.search(key) << endl;
        } 
        else if (choice == 4) {
            cout << ht.display();
        } 
        else if (choice == 5) {
            break;
        } 
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
