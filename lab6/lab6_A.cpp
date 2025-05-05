//stack using array

#include <iostream>
using namespace std;

#define SIZE 5 

class Stack { 
private:
    char arr[SIZE]; 
    int top; 

public:
    Stack() { top = -1; } // Constructor initializes stack as empty

    // Push operation
    void push(char value) {
        if (top >= SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    // Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Nothing to pop.\n";
        } else {
            cout << "Popped element: " << arr[top--] << endl;
        }
    }

    // Peek operation
    void peek() {
        if (top < 0) {
            cout << "Stack is empty. No top element.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
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
