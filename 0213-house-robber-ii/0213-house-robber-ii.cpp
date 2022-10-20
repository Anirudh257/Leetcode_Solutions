class Solution {
public:
    
    // Time complexity: O(N), Space complexity: O(N) + auxiliary stack space O(N)
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp(size, -1);
        vector<int> dp2(size, -1);
        
        return max(compMaxAmt(nums, size - 2, 0, dp), compMaxAmt(nums, size - 1, 1, dp2));
    }
private:
    int compMaxAmt(vector<int>& nums, int ind, int lastInd, vector<int>& dp) {
        if (ind < lastInd) {
            return 0;
        } 
        
        if (ind == lastInd) {
            return nums[ind];
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int take = nums[ind] + compMaxAmt(nums, ind - 2, lastInd, dp);
        int notTake = compMaxAmt(nums, ind - 1, lastInd, dp);
        
        return dp[ind] = max(take, notTake);
    }
};