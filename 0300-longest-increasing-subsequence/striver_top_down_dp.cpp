// Time complexity: O(n^2), Space complexity: O(n^2) + Auxiliary Stack Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));
        return compLIS(nums, 0, -1, size, dp);
    }
private:
    int compLIS(vector<int>& nums, int ind, int prevInd, int size, vector<vector<int>>& dp) {
        if (ind == size) {
            return 0;
        }
        if (dp[ind][prevInd + 1] != -1) {
            return dp[ind][prevInd + 1];
        }

        int len = 0;
        if (prevInd == -1 || nums[prevInd] < nums[ind]) {
            len = 1 + compLIS(nums, ind + 1, ind, size, dp);
        }
        len = max(len, compLIS(nums, ind + 1, prevInd, size, dp));

        return dp[ind][prevInd + 1] = len;
    }
};