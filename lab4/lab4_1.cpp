#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class ListADT {
    Node* head;

public:
    ListADT() {
        head = nullptr;
    }

    ~ListADT() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node* createNode(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        return newNode;
    }

    void insertBeginning(int x) {
        Node* n = createNode(x);
        n->next = head;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = createNode(x);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void insertPosition(int x, int pos) {
        if (pos < 0) return;
        if (pos == 0) {
            insertBeginning(x);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp; i++) temp = temp->next;
        if (!temp) return;
        Node* n = createNode(x);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deletePosition(int pos) {
        if (!head || pos < 0) return;
        if (pos == 0) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next; i++) temp = temp->next;
        if (!temp->next) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    int search(int x) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == x) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayReverse(Node* node) {
        if (!node) return;
        displayReverse(node->next);
        cout << node->data << " ";
    }

    void showReverse() {
        displayReverse(head);
        cout << "\n";
    }

    void reverseLink() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main() {
    ListADT list;
    int choice;

    do {
        cout << "\nMenu:\n1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Display Reverse\n10.Reverse Link\n11.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x; cin >> x;
            list.insertBeginning(x);
        } else if (choice == 2) {
            int x; cin >> x;
            list.insertEnd(x);
        } else if (choice == 3) {
            int x, pos; cin >> x >> pos;
            list.insertPosition(x, pos);
        } else if (choice == 4) {
            list.deleteBeginning();
        } else if (choice == 5) {
            list.deleteEnd();
        } else if (choice == 6) {
            int pos; cin >> pos;
            list.deletePosition(pos);
        } else if (choice == 7) {
            int x; cin >> x;
            int index = list.search(x);
            if (index == -1) cout << "Not found\n";
            else cout << "Found at index " << index << "\n";
        } else if (choice == 8) {
            list.display();
        } else if (choice == 9) {
            list.showReverse();
        } else if (choice == 10) {
            list.reverseLink();
        }

    } while (choice != 11);

    return 0;
}
