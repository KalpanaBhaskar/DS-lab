#include <iostream>
#include <vector>
#include "sortlib.h"

int linearsearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarysearch(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void printarray(const std::vector<int>& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size() - 1; i++) {
        std::cout << " " << arr[i] << " ,";
    }
    std::cout << " " << arr.back() << " ]\n";
}

int main() {
    int num;
    std::cout << "enter number of elements in array: ";
    std::cin >> num;
    while (num < 2) {
        std::cout << "reenter valid number >=2: ";
        std::cin >> num;
    }

    std::vector<int> arr(num);
    for (int i = 0; i < num; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> sorted = bubblesort(arr);
    std::cout << "sorted array using bubble sort:\n";
    printarray(sorted);

    char choice;
    while (true) {
        std::cout << "MENU:\na: linear search\nb: binary search\nc: exit\n";
        std::cout << "enter character corresponding to choice of operation: ";
        std::cin >> choice;

        if (choice == 'a') {
            int key;
            std::cout << "enter element to search: ";
            std::cin >> key;
            int index = linearsearch(arr, key);
            if (index != -1)
                std::cout << "element found at index " << index << "\n";
            else
                std::cout << "element not found\n";
        }

        if (choice == 'b') {
            int key;
            std::cout << "enter element to search: ";
            std::cin >> key;
            int index = binarysearch(sorted, key);
            if (index != -1)
                std::cout << "element found at index " << index << " in sorted array\n";
            else
                std::cout << "element not found in sorted array\n";
        }

        if (choice == 'c') {
            std::cout << "exited\n";
            break;
        }
    }

    return 0;
}
