//StackADT header file for infix and postfix evaluation program

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

class StackADT {
private:
    struct node {
        int data;
        node* next;
    } *head, *tail;

public:
    StackADT() { head = tail = NULL; }

    void Push(int);
    int Pop();
    int Peek();
    bool isEmpty();
};

//Push to the end using tail pointer
void StackADT::Push(int num) {
    node* newnode = new node();
    newnode->data = num;
    newnode->next = NULL;

    if (tail == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

//Pop from the end using tail pointer
int StackADT::Pop() {
    if (head == NULL) {
        cout << "Stack Underflow\n";
        exit(EXIT_FAILURE);
    }

    int data;
    if (head == tail) {
        data = head->data;
        delete head;
        head = tail = NULL;
    } else {
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        data = tail->data;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    return data;
}

//Peek the top element (from tail)
int StackADT::Peek() {
    if (tail == NULL) {
        cout << "Stack is empty\n";
        return -1;
    }
    return tail->data;
}

//Check if stack is empty
bool StackADT::isEmpty() {
    return head == NULL;
}

#endif
