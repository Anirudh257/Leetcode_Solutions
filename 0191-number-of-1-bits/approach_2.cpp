class Solution {
public:
    // Time complexity: O(1) Space complexity: O(1)
    int hammingWeight(uint32_t n) {
        int bits = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                bits++;
            }
            mask = ((unsigned int)mask) << 1; // To avoid left shift error
        }
        return bits;
    }        
};
