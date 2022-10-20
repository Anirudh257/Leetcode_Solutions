class Solution {
public:
    int rob(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(N) + O(N) auxiliary stack space
        int size = nums.size();
        vector<int> dp(size, -1);
        return compMaxAmt(nums, size - 1, dp);
    }
private:
    int compMaxAmt(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind < 0) {
            return 0;
        }
        if (ind == 0) {
            return nums[ind];
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int take = nums[ind] + compMaxAmt(nums, ind - 2, dp);
        int notTake = compMaxAmt(nums, ind - 1, dp);
        
        return dp[ind] = max(take, notTake);
        
    }
};
