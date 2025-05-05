#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<string>> words(3, vector<string>(n)); // Stores words of each player
    unordered_map<string, int> freq; // Stores frequency of each word
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> words[i][j];
            freq[words[i][j]]++;
        }
    }
    
    vector<int> score(3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string word = words[i][j];
            if (freq[word] == 1) score[i] += 3; // Unique word → 3 points
            else if (freq[word] == 2) score[i] += 1; // Appears twice → 1 point
        }
    }

    cout << score[0] << " " << score[1] << " " << score[2] << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
