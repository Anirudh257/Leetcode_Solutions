class Solution {
public:
    int rob(vector<int>& nums) {
        // Time complexity: O(n), Space complexity: O(N) + Auxiliary Stack Space: O(N)
        int size = nums.size();
        vector<int> dp(size, -1);
        
        return compMaxAmt(nums, 0, size, 0, dp);
    }
private:
    int compMaxAmt(vector<int>& nums, int ind, int size, int amt, vector<int>& dp) {
        if (ind >= size) {
            return 0;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int take = 0;
        int notTake = 0;
        
        take = nums[ind] + compMaxAmt(nums, ind + 2, size, amt, dp);
        notTake = compMaxAmt(nums, ind + 1, size, amt, dp);
        
        return dp[ind] = max(take, notTake);
    }
};
