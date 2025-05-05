#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
    int table[TABLE_SIZE];

public:
    HashTable();

    int hash(int key);

    string insert(int key);
    string remove(int key);
    string search(int key);
    string display();
};

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

string HashTable::insert(int key) {
    int index = hash(key);
    int i = 0;
    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
            table[newIndex] = key;
            return "Inserted at index " + to_string(newIndex);
        }
        i++;
    }
    return "Hash table is full";
}
// write a function to delete a key from the hash table

string HashTable::remove(int key) {
    int index = hash(key);
    int i = 0;
    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == key) {
            table[newIndex] = DELETED;
            return "Deleted key at index " + to_string(newIndex);
        } else if (table[newIndex] == EMPTY) {
            break;
        }
        i++;
    }
    return "Key not found";
}
#write a function to search for a key in the hash table using quadratic probing

string HashTable::search(int key) {
    int index = hash(key);
    int i = 0;
    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (table[newIndex] == key)
            return "Key found at index " + to_string(newIndex);
        else if (table[newIndex] == EMPTY)
            break;
        i++;
    }
    return "Key not found";
}

string HashTable::display() {
    string result = "";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY)
            result += to_string(i) + " : EMPTY\n";
        else if (table[i] == DELETED)
            result += to_string(i) + " : DELETED\n";
        else
            result += to_string(i) + " : " + to_string(table[i]) + "\n";
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
        } else if (choice == 2) {
            cout << "Enter key to delete: ";
            cin >> key;
            cout << ht.remove(key) << endl;
        } else if (choice == 3) {
            cout << "Enter key to search: ";
            cin >> key;
            cout << ht.search(key) << endl;
        } else if (choice == 4) {
            cout << ht.display();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
