#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAscending(int value) {
        Node* newNode = new Node(value);
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    static LinkedList merge(LinkedList& list1, LinkedList& list2) {
        LinkedList mergedList;
        Node* t1 = list1.head;
        Node* t2 = list2.head;
        Node** tail = &mergedList.head;
        
        while (t1 && t2) {
            if (t1->data <= t2->data) {
                *tail = t1;
                t1 = t1->next;
            } else {
                *tail = t2;
                t2 = t2->next;
            }
            tail = &((*tail)->next);
        }
        *tail = (t1) ? t1 : t2;
        
        list1.head = nullptr;
        list2.head = nullptr;
        
        return mergedList;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
#endif