class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        
        if (n == 1) {
            return {0, 1};
        }        
        
        vector<int> bits(n + 1, 0);
        bits[0] = 0;
        
        for(int i = 1; i<= n; i++) {
            bits[i] = bits[i>>1] + i % 2;
        }
        
        return bits;
    }
};