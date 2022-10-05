class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size(), l = 0, r = 0;
        int maxConsOnes = 0, numZeros = 0;
        
        while(r < size) {
            if (nums[r] == 0) {
                numZeros++;
            }
            
            while(numZeros >= 2) {
                if (nums[l] == 0) {
                    numZeros--;
                }
                l++;
            }
            
            maxConsOnes = max(r - l + 1, maxConsOnes);
            r++;
        }
        
        return maxConsOnes;
    }
};