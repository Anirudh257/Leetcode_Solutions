class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        //Time complexity: O(1), Space complexity: O(1)
        
        //Swap first 16 digits with 2nd 16 digits
        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        
        // Swap 8 digits in each respective part separately.
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        
        // Swap 4 digits in each respective part separately.
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        
        // Swap 2 digits in each respective part separately.
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        
        // Swap 1 digit in each respective part separately.
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
};
