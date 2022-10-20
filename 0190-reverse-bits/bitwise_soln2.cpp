class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        // Time complexity: O(32), Space complexity: O(1)
        for (int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        
        return res;
    }
};