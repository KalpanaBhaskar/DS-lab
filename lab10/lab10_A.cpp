#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> seen;
    int min_prefix = 0;

    // Traverse from the end to find the earliest duplicate
    for (int i = n - 1; i >= 0; i--) {
        if (seen.count(a[i])) break;
        seen.insert(a[i]);
        min_prefix++;
    }

    cout << n - min_prefix << "\n";  // Elements to remove
}

int main() {
   
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
