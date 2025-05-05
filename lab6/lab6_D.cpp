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
    Node* top;
public:
    Stack() { top = nullptr; }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) return '#'; // Error condition
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};

// Function to check if parentheses are valid
bool isValidParentheses(string expr) {
    Stack stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } 
        else {
            if (stack.isEmpty()) return false;
            char top = stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string expr;
    cout << "Enter a string of parentheses: ";
    cin >> expr;

    if (isValidParentheses(expr)) {
        cout << "Valid parentheses expression.\n";
    } else {
        cout << "Invalid parentheses expression.\n";
    }

    return 0;
}