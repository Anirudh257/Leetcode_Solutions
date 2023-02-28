class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int size = nums.size();
        int reqSum = sum/2;
        vector<vector<int>> dp(size, vector<int>(reqSum + 1, -1));
        return checkPart(nums, size - 1, reqSum, dp);
    }
private:
    bool checkPart(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (ind == 0) {
            return (nums[ind] == sum);
        }
        if (dp[ind][sum] != -1) {
            return dp[ind][sum];
        }

        bool notTake = checkPart(nums, ind - 1, sum, dp);
        bool take = false;
        if (sum >= nums[ind]) {
            take = checkPart(nums, ind - 1, sum - nums[ind], dp);
        }
        return dp[ind][sum] = take | notTake;
    }
};