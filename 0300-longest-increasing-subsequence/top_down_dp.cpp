// Time complexity: O(n^2), Space complexity: O(n^2) + Auxiliary Stack Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size + 1, -1));
        return compLIS(nums, size - 1, size, INT_MIN, dp);
    }
private:
    int compLIS(vector<int>& nums, int ind, int prevInd, int prev, vector<vector<int>>& dp) {
        if (ind < 0) {
            return 0;
        }

        if (dp[ind][prevInd] != -1) {
            return dp[ind][prevInd];
        }

        int take = 0, notTake = 0;
        if (prev == INT_MIN) {
            take = 1 + compLIS(nums, ind - 1, ind, nums[ind], dp);
            notTake = compLIS(nums, ind - 1, prevInd, prev, dp);
        }
        else {
            if (nums[ind] < prev) {
                take = 1 + compLIS(nums, ind - 1, ind, nums[ind], dp);
            }
            notTake = compLIS(nums, ind - 1, prevInd, prev, dp);
        }

        return dp[ind][prevInd] = max(take, notTake);
    }
};