#include <iostream>
#include <vector>

std::vector<int> bubblesort(const std::vector<int>& arr) {
    std::vector<int> sorted = arr;
    int n = sorted.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    return sorted;
}

std::vector<int> selectionsort(const std::vector<int>& arr) {
    std::vector<int> sorted = arr;
    int n = sorted.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (sorted[j] < sorted[min]) {
                min = j;
            }
        }
        int temp = sorted[min];
        sorted[min] = sorted[i];
        sorted[i] = temp;
    }
    return sorted;
}

std::vector<int> insertionsort(const std::vector<int>& arr) {
    std::vector<int> sorted = arr;
    int n = sorted.size();
    for (int i = 1; i < n; i++) {
        int key = sorted[i];
        int j = i - 1;
        while (j >= 0 && sorted[j] > key) {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = key;
    }
    return sorted;
}

void printarray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size() - 1; i++) {
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

    printarray(arr);
    std::cout << "MENU: \na: bubble sort \nb: selection sort \nc: insertion sort \nd: exit\n";

    char choice;
    while (true) {
        std::cout << "enter character corresponding to choice of operation: ";
        std::cin >> choice;
        if (choice == 'a') {
            std::vector<int> result = bubblesort(arr);
            std::cout << "array after bubble sort:\n";
            printarray(result);
        }
        if (choice == 'b') {
            std::vector<int> result = selectionsort(arr);
            std::cout << "array after selection sort:\n";
            printarray(result);
        }
        if (choice == 'c') {
            std::vector<int> result = insertionsort(arr);
            std::cout << "array after insertion sort:\n";
            printarray(result);
        }
        if (choice == 'd') {
            std::cout << "exited\n";
            break;
        }
    }

    return 0;
}