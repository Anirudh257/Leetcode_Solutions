class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        vector<int> bits(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        
        
        return bits;
    }
};
