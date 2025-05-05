#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        long long blocks[200000];
        for (int i = 0; i < n; i++) {
            std::cin >> blocks[i];
        }
        
        long long max_blocks = blocks[0];
        
        for (int i = 1; i < n; i++) {
            if (blocks[i] > blocks[0]) {
                long long moves = (blocks[i] - blocks[0] + 1) / 2;
                max_blocks += moves;
            }
        }
        
        std::cout << max_blocks << std::endl;
    }
    
    return 0;
}
