
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find max1 and max2
pair<int, int> findTwoMax(const vector<int>& strengths) {
    int max1 = *max_element(strengths.begin(), strengths.end());
    int max2 = INT_MIN;

    for (int s : strengths) {
        if (s != max1) {
            max2 = max(max2, s);
        }
    }

    // Edge case: If all strengths are the same, set max2 = max1
    if (max2 == INT_MIN) {
        max2 = max1;
    }

    return {max1, max2};
}

// Function to calculate strength differences
vector<int> calculateDifferences(int n, const vector<int>& strengths) {
    vector<int> result(n);
    auto [max1, max2] = findTwoMax(strengths);

    for (int i = 0; i < n; i++) {
        result[i] = (strengths[i] == max1) ? strengths[i] - max2 : strengths[i] - max1;
    }

    return result;
}

// Main function
int main() {
    int t;
    cin >> t;
    vector<vector<int>> results;

    while (t--) {
        int n;
        cin >> n;
        vector<int> strengths(n);

        for (int& s : strengths) {
            cin >> s;
        }

        results.push_back(calculateDifferences(n, strengths));
    }

    // Efficient batch output
    for (const auto& res : results) {
        for (int val : res) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}