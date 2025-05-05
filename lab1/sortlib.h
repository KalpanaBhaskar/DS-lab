#ifndef SORTLIB_H
#define SORTLIB_H

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

#endif
