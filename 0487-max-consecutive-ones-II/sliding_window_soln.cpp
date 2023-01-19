// Time complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Sliding window approach: Only 1 zero allowed in a sequence
        int size = nums.size(), maxLen = 0, numZeros = 0, l = 0, r = 0;
        
        while(r < size) {
            if (nums[r] == 0) {
                numZeros++;
            }

            while(numZeros == 2) {
                if (nums[l] == 0) {
                    numZeros--;
                }
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
