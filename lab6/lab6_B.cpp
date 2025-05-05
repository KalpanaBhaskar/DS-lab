//stack using linked list

#include <iostream>
using namespace std;

// Node structure for the stack
struct Node {
    char data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() { top = nullptr; } // Constructor initializes stack as empty

    // Push operation
    void push(char value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack.\n";
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Nothing to pop.\n";
        } else {
            cout << "Popped element: " << top->data << endl;
            Node* temp = top;
            top = top->next;
            delete temp; // Free memory
        }
    }

    // Peek operation
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty. No top element.\n";
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;
    int choice;
    char value;

    do {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
