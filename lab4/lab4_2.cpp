#include <iostream>

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

    // Private function to get the head of the list
    Node* getHead() const {
        return head;
    }

public:
    List() : head(nullptr) {}

    // Function to insert in ascending order
    void insertAscending(int value) {
        Node* newNode = new Node(value);

        if (!head || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to merge another list into this list (sorted merge)
    void merge(List& other) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        Node* l1 = this->getHead();
        Node* l2 = other.getHead();

        while (l1 && l2) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1) ? l1 : l2;
        head = dummy->next;
        delete dummy;

        // Clear the other list after merging
        other.head = nullptr;
    }

    // Function to display the list
    void display() const {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    ~List() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    List list1, list2;
    int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert Ascending\n";
        std::cout << "2. Merge Another List\n";
        std::cout << "3. Display List\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list1.insertAscending(value);
            break;
        case 2:
            std::cout << "Enter values for second list (-1 to stop):\n";
            while (true) {
                std::cin >> value;
                if (value == -1) break;
                list2.insertAscending(value);
            }
            list1.merge(list2);
            std::cout << "Lists merged successfully!\n";
            break;
        case 3:
            std::cout << "Current List: ";
            list1.display();
            break;
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
