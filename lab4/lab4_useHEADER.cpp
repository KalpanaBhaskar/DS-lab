#include "lab4_HEADER.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list1, list2, list3;
    int choice, value;
    
    do {
        cout << "\n1. Insert List1\n2. Insert List2\n3. Merge into List3\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value for List1: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                cout << "Enter value for List2: ";
                cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3 = LinkedList::merge(list1, list2);
                cout << "Lists merged into List3.\n";
                break;
            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3: ";
                list3.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    
    return 0;
}
