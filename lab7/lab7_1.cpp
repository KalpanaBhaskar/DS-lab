#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Function to enqueue an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << ".\n";
            return;
        }

        if (front == -1) front = 0; // Set front on first enqueue
        arr[++rear] = value;
        cout << value << " enqueued successfully.\n";
    }

    // Function to dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " dequeued successfully.\n";
        if (front == rear) { // Reset queue when last element is removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to get the front element (Peek)
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
