#include <iostream>
#include <cctype>
#include <cstring>
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
    
    char peek() {
        if (top == nullptr) return '#';
        return top->data;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};

// Function to define precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch; // Append operands directly
        } 
        else if (ch == '(') {
            stack.push(ch);
        } 
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(')
                postfix += stack.pop();
            stack.pop(); // Remove '('
        } 
        else { // Operator
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch))
                postfix += stack.pop();
            stack.push(ch);
        }
    }

    while (!stack.isEmpty())
        postfix += stack.pop();

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack stack;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } 
        else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
            }
        }
    }
    return stack.pop();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
