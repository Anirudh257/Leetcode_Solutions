class Solution {
public:
    // Time complexity: O(1) Space complexity: O(1)
    int hammingWeight(uint32_t n) {
        int numBits = 0;
        
        while (n != 0) {
            numBits++;
            n = n & (n - 1);
        }
        return numBits;
    }        
};
