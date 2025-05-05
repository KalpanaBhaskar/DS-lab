#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    bool insert(int value);
    bool deleteMax();
    vector<int> display() const;
    bool search(int value) const;
    vector<int> heapSort() const;
};

void MaxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] <= heap[parent]) break;
        swap(heap[index], heap[parent]);
        index = parent;
    }
}

void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest == index) break;
        swap(heap[index], heap[largest]);
        index = largest;
    }
}

bool MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
    return true;
}

bool MaxHeap::deleteMax() {
    if (heap.empty()) return false;
    
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    
    return true;
}

vector<int> MaxHeap::display() const {
    return heap;
}

bool MaxHeap::search(int value) const {
    return find(heap.begin(), heap.end(), value) != heap.end();
}

vector<int> MaxHeap::heapSort() const {
    vector<int> tempHeap = heap;
    sort(tempHeap.rbegin(), tempHeap.rend());
    return tempHeap;
}

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\nPriority Queue (Max Heap) Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete Max\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                if (pq.deleteMax()) 
                    cout << "Max element deleted successfully.\n";
                else 
                    cout << "Heap is empty!\n";
                break;
            case 3: {
                vector<int> heapElements = pq.display();
                if (heapElements.empty()) 
                    cout << "Heap is empty!\n";
                else {
                    cout << "Heap elements: ";
                    for (int val : heapElements) cout << val << " ";
                    cout << endl;
                }
                break;
            }
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (pq.search(value))
                    cout << "Element " << value << " found in heap.\n";
                else
                    cout << "Element " << value << " not found in heap.\n";
                break;
            case 5: {
                vector<int> sortedHeap = pq.heapSort();
                cout << "Sorted elements: ";
                for (int val : sortedHeap) cout << val << " ";
                cout << endl;
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}