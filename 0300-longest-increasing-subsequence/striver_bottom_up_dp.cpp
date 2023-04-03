// Time complexity: O(n^2), Space complexity: O(n^2) 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

        for (int ind = size - 1; ind >= 0; ind--) {
            for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
                int len = 0;
                if (prevInd == -1 || nums[prevInd] < nums[ind]) {
                    len = 1 + dp[ind + 1][ind + 1];
                }
                len = max(len, dp[ind + 1][prevInd + 1]);

                dp[ind][prevInd + 1] = len;            
            }
        }

        // return compLIS(nums, 0, -1, size, dp);
        return dp[0][0];
    }
};