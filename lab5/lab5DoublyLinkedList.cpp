#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    void InsertBeginning(int);
    void InsertEnd(int);
    void InsertPosition(int, int);
    int DeleteBeginning();
    int DeleteEnd();
    int DeletePosition(int);
    void Search(int);
    void Display();
    ~DoublyLinkedList();
};

// Constructor
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

// Insert at beginning
void DoublyLinkedList::InsertBeginning(int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (!head) head = tail = newNode;
    else {
        head->prev = newNode;
        head = newNode;
    }
    cout << "Inserted at Beginning: " << value << endl;
}

// Insert at end
void DoublyLinkedList::InsertEnd(int value) {
    Node* newNode = new Node{value, tail, nullptr};
    if (!tail) head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Inserted at End: " << value << endl;
}

// Insert at a position
void DoublyLinkedList::InsertPosition(int value, int pos) {
    if (pos <= 1) {
        InsertBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp) {
        InsertEnd(value);
        return;
    }

    Node* newNode = new Node{value, temp, temp->next};
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Inserted at Position " << pos << ": " << value << endl;
}

// Delete from beginning
int DoublyLinkedList::DeleteBeginning() {
    if (!head) {
        cout << "List is Empty\n";
        return -1;
    }
    int deletedValue = head->data;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    cout << "Deleted from Beginning: " << deletedValue << endl;
    return deletedValue;
}

// Delete from end
int DoublyLinkedList::DeleteEnd() {
    if (!tail) {
        cout << "List is Empty\n";
        return -1;
    }
    int deletedValue = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    cout << "Deleted from End: " << deletedValue << endl;
    return deletedValue;
}

// Delete from a given position
int DoublyLinkedList::DeletePosition(int pos) {
    if (!head) {
        cout << "List is Empty\n";
        return -1;
    }
    if (pos == 1) return DeleteBeginning();

    Node* temp = head;
    for (int i = 1; temp && i < pos; i++)
        temp = temp->next;

    if (!temp) {
        cout << "Position Out of Range\n";
        return -1;
    }

    int deletedValue = temp->data;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp == tail) tail = temp->prev;

    delete temp;
    cout << "Deleted from Position " << pos << ": " << deletedValue << endl;
    return deletedValue;
}

// Search for a value
void DoublyLinkedList::Search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Value " << value << " found at Position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << value << " Not Found\n";
}

// Display the list
void DoublyLinkedList::Display() {
    if (!head) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
    while (head) DeleteBeginning();
}

// Main function
int main() {
    DoublyLinkedList dll;
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
            cin >> value; dll.InsertBeginning(value); 
            break;

            case 2: 
            cout << "Enter Value: "; 
            cin >> value; dll.InsertEnd(value); 
            break;

            case 3: 
            cout << "Enter Value and Position: "; 
            cin >> value >> pos; dll.InsertPosition(value, pos); 
            break;

            case 4: 
            dll.DeleteBeginning(); 
            break;

            case 5: 
            dll.DeleteEnd(); 
            break;

            case 6: 
            cout << "Enter Position: "; 
            cin >> pos; dll.DeletePosition(pos); 
            break;

            case 7: 
            cout << "Enter Value to Search: "; 
            cin >> value; dll.Search(value); 
            break;

            case 8: 
            dll.Display(); 
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