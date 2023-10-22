class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Time complexity: O(2N), Space complexity: O(1)
        int size = nums.size(), numZeros = 0, maxConsOnes = 0;
        int l = 0, r = 0;
        
        while(r < size) {
            if (nums[r] == 0) {
                numZeros++;
            }
            
            while(numZeros > k) {
                if (nums[l] == 0) {
                    numZeros--;
                }
                l++;
            }
            maxConsOnes = max(maxConsOnes, r - l + 1);
            r++;
        }
        
        
        return maxConsOnes;
    }
};