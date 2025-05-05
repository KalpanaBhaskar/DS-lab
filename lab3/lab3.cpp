#include <iostream>
using namespace std;

class List {
    int arr[5];
    int size;
public:
    List() : size(0) {}

    int insertBegin(int num);
    int insertEnd(int num);
    int insertPos(int num, int pos);
    int deleteBegin();
    int deleteEnd();
    int deletePos(int pos);
    int search(int num);
    void display();
    int rotate(int k);
};

int List::insertBegin(int num) {
    if (size == 5) {
        cout << "List is full!\n";
        return -1;
    }
    for (int i = size; i > 0; --i) arr[i] = arr[i - 1];
    arr[0] = num;
    size++;
    cout << "Inserted at position: 1\n";
    return 0;
}

int List::insertEnd(int num) {
    if (size == 5) {
        cout << "List is full\n";
        return -1;
    }
    arr[size++] = num;
    cout << "Inserted at position: " << size << "\n";
    return 0;
}

int List::insertPos(int num, int pos) {
    if (size == 5 || pos < 1 || pos > size + 1) {
        cout << "Invalid position!\n";
        return -1;
    }
    for (int i = size; i >= pos; --i) arr[i] = arr[i - 1];
    arr[pos - 1] = num;
    size++;
    cout << "Inserted at position: " << pos << "\n";
    return 0;
}

int List::deleteBegin() {
    if (size == 0) {
        cout << "List is empty\n";
        return -1;
    }
    int deleted = arr[0];
    for (int i = 1; i < size; i++) arr[i - 1] = arr[i];
    size--;
    cout << "Deleted " << deleted << " from position: 1\n";
    return deleted;
}

int List::deleteEnd() {
    if (size == 0) {
        cout << "List is empty\n";
        return -1;
    }
    int deleted = arr[size - 1];
    size--;
    cout << "Deleted " << deleted << " from position: " << size + 1 << "\n";
    return deleted;
}

int List::deletePos(int pos) {
    if (size == 0 || pos < 1 || pos > size) {
        cout << "Invalid position\n";
        return -1;
    }
    int deleted = arr[pos - 1];
    for (int i = pos - 1; i < size - 1; ++i) arr[i] = arr[i + 1];
    size--;
    cout << "Deleted " << deleted << " from position: " << pos << "\n";
    return deleted;
}

int List::search(int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            cout << "Found at position: " << i + 1 << "\n";
            return i + 1;
        }
    }
    cout << "Not found\n";
    return -1;
}

void List::display() {
    if (size == 0) {
        cout << "List is empty!\n";
        return;
    }
    cout << "Current List: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}

int List::rotate(int k) {
    if (size == 0) {
        cout << "List is empty!\n";
        return -1;
    }
    k %= size;
    if (k == 0) return 0;
    for (int i = 0; i < k; i++) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) arr[j] = arr[j - 1];
        arr[0] = temp;
    }
    cout << "Rotated by: " << k << "\n";
    return 0;
}

int main() {
    List l;
    int choice, num, pos, k, element, deleted;

    cout << "Enter 5 elements:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> element;
        l.insertEnd(element);
    }    
    l.display();
    
    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter number: ";
                cin >> num;
                l.insertBegin(num);
                break;
            case 2:
                cout << "Enter number: ";
                cin >> num;
                l.insertEnd(num);
                break;
            case 3:
                cout << "Enter number: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> pos;
                l.insertPos(num, pos);
                break;
            case 4:
                deleted = l.deleteBegin();
                if (deleted != -1) cout << "Deleted: " << deleted << "\n";
                break;
            case 5:
                deleted = l.deleteEnd();
                if (deleted != -1) cout << "Deleted: " << deleted << "\n";
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleted = l.deletePos(pos);
                if (deleted != -1) cout << "Deleted: " << deleted << "\n";
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> num;
                l.search(num);
                break;
            case 8:
                l.display();
                break;
            case 9:
                cout << "Enter number of rotations: ";
                cin >> k;
                l.rotate(k);
                break;
        }
    } while (choice != 10);
    
    return 0;
}