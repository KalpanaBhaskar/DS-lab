#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findWinners(int q, int kMin) {
    return (q > kMin) ? kMin - 1 : q;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int k, q;
        cin >> k >> q;

        vector<int> removePositions(k);
        for (int i = 0; i < k; i++) {
            cin >> removePositions[i];
        }

        vector<int> startPlayers(q);
        for (int i = 0; i < q; i++) {
            cin >> startPlayers[i];
        }

        int kMin = *min_element(removePositions.begin(), removePositions.end());

        for (int n : startPlayers) {
            cout << findWinners(n, kMin) << " ";
        }
        cout << endl;
    }

    return 0;
}
