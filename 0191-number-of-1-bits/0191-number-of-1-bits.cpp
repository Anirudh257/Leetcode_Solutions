class Solution {
public:
    // Time complexity: O(k), k = number of bits, Space complexity: O(1)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0) {
            count += (n & 1);
            
            n = n >> 1;
            
            // cout << n <<  endl;
        }
        
        return count;     
    }
};