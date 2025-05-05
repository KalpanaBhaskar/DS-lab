#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList();
    void InsertBeginning(int value);
    void InsertEnd(int value);
    void InsertPosition(int value, int pos);
    int DeleteBeginning();
    int DeleteEnd();
    int DeletePosition(int pos);
    void Search(int value);
    void Display();
    ~CircularLinkedList();
};

// Constructor
CircularLinkedList::CircularLinkedList() {
    tail = nullptr;
}

// Insert at the beginning
void CircularLinkedList::InsertBeginning(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    cout << "Inserted at Beginning: " << value << endl;
}

// Insert at the end
void CircularLinkedList::InsertEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Inserted at End: " << value << endl;
}

// Insert at a given position
void CircularLinkedList::InsertPosition(int value, int pos) {
    if (pos <= 1) {
        InsertBeginning(value);
        return;
    }

    Node* temp = tail->next;
    for (int i = 1; temp != tail && i < pos - 1; i++)
        temp = temp->next;

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
    if (temp == tail) tail = newNode;

    cout << "Inserted at Position " << pos << ": " << value << endl;
}

// Delete from beginning
int CircularLinkedList::DeleteBeginning() {
    if (!tail) {
        cout << "List is Empty\n";
        return -1;
    }

    Node* temp = tail->next;
    int deletedValue = temp->data;

    if (tail == temp) {
        tail = nullptr;
    } else {
        tail->next = temp->next;
    }

    delete temp;
    cout << "Deleted from Beginning: " << deletedValue << endl;
    return deletedValue;
}

// Delete from end
int CircularLinkedList::DeleteEnd() {
    if (!tail) {
        cout << "List is Empty\n";
        return -1;
    }

    Node* temp = tail->next;
    int deletedValue = tail->data;

    if (tail == temp) {
        tail = nullptr;
    } else {
        while (temp->next != tail)
            temp = temp->next;
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    cout << "Deleted from End: " << deletedValue << endl;
    return deletedValue;
}

// Delete from a given position
int CircularLinkedList::DeletePosition(int pos) {
    if (!tail) {
        cout << "List is Empty\n";
        return -1;
    }
    if (pos == 1) return DeleteBeginning();

    Node* temp = tail->next;
    Node* prev = nullptr;

    for (int i = 1; temp != tail && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == tail) return DeleteEnd();

    if (prev) prev->next = temp->next;
    int deletedValue = temp->data;
    delete temp;

    cout << "Deleted from Position " << pos << ": " << deletedValue << endl;
    return deletedValue;
}

// Search for a value
void CircularLinkedList::Search(int value) {
    if (!tail) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = tail->next;
    int pos = 1;
    do {
        if (temp->data == value) {
            cout << "Value " << value << " found at Position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail->next);

    cout << "Value " << value << " Not Found\n";
}

// Display the list
void CircularLinkedList::Display() {
    if (!tail) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = tail->next;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

// Destructor
CircularLinkedList::~CircularLinkedList() {
    while (tail) DeleteBeginning();
}

// Main function
int main() {
    CircularLinkedList cll;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
            cout << "Enter Value: "; 
            cin >> value; 
            cll.InsertBeginning(value); 
            break;

            case 2: 
            cout << "Enter Value: "; 
            cin >> value; 
            cll.InsertEnd(value);
            break;

            case 3: 
            cout << "Enter Value and Position: "; 
            cin >> value >> pos; 
            cll.InsertPosition(value, pos); 
            break;

            case 4: 
            cll.DeleteBeginning(); 
            break;

            case 5: 
            cll.DeleteEnd(); 
            break;

            case 6: 
            cout << "Enter Position: "; 
            cin >> pos; 
            cll.DeletePosition(pos); 
            break;

            case 7: 
            cout << "Enter Value to Search: "; 
            cin >> value; 
            cll.Search(value); 
            break;

            case 8: 
            cll.Display(); 
            break;

            case 9: 
            cout << "Exiting...\n"; 
            break;

            default: 
            cout << "Invalid Choice, Try Again\n";
        }
    } while (choice != 9);

    return 0;
}
