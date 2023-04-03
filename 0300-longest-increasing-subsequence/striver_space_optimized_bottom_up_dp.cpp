// Time complexity: O(n^2), Space complexity: O(n) 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> next(size + 1, 0), curr(size + 1, 0);

        for (int ind = size - 1; ind >= 0; ind--) {
            for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
                int len = 0;
                if (prevInd == -1 || nums[prevInd] < nums[ind]) {
                    len = 1 + next[ind + 1];
                }
                len = max(len, next[prevInd + 1]);

                curr[prevInd + 1] = len;            
            }
            next = curr;
        }

        // return compLIS(nums, 0, -1, size, dp);
        return next[0];
    }
};