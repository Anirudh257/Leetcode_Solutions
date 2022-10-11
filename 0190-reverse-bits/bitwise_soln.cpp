class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Time complexity: O(32), Space complexity: O(1)
        uint32_t res = 0, power = 31;
        
        while(n) {
            res += (n & 1) << power;
            n = n >> 1;
            power--;
        }
        return res;
    }
};
