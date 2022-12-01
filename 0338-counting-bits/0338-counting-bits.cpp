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
        
        
        vector<int> bits(n + 1, -1);
        bits[0] = 0;
        bits[1] = 1;
        bits[2] = 1;
        
        if (n == 1) {
            return bits;
        }
        
        
        for(int i = 3; i<= n; i++) {
            if (bits[i] == -1) {
                bits[i] = bits[i>>1] + bits[i%2];
            }
        }
        
        return bits;
    }
};