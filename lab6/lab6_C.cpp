//Program to implemt infix and postfix evaluation
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include "stack.h" 
using namespace std;

int precedence(char);
string infixToPostfix(string);
int evaluatePostfix(string);

// Main function with menu-driven implementation
int main() {
    int choice;
    string infixExpression, postfixExpression;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                getline(cin, infixExpression);
                break;

            case 2:
                if (infixExpression.empty()) {
                    cout << "No infix expression entered!\n";
                } else {
                    postfixExpression = infixToPostfix(infixExpression);
                    cout << "Postfix Expression: " << postfixExpression << endl;
                }
                break;

            case 3:
                if (postfixExpression.empty()) {
                    cout << "No postfix expression available!\n";
                } else {
                    cout << "Evaluation Result: " << evaluatePostfix(postfixExpression) << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    StackADT s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) { 
            postfix += ch;
        } else if (ch == '(') {
            s.Push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.Peek() != '(') {
                postfix += s.Pop();
            }
            s.Pop();
        } else {
            while (!s.isEmpty() && precedence(s.Peek()) >= precedence(ch)) {
                postfix += s.Pop();
            }
            s.Push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.Pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    StackADT s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.Push(ch - '0'); 
        } else { 
            int val2 = s.Pop();
            int val1 = s.Pop();
            switch (ch) {
                case '+': 
                    s.Push(val1 + val2); 
                    break;
                case '-': 
                    s.Push(val1 - val2); 
                    break;
                case '*': 
                    s.Push(val1 * val2); 
                    break;
                case '/': 
                    s.Push(val1 / val2); 
                    break;
            }
        }
    }
    return s.Pop();
}