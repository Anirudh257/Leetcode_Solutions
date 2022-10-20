class Solution {
public:
    int rob(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(N) 
        int size = nums.size();
        vector<int> dp(size, 0);
        
        dp[0] = nums[0];
        
        for (int i = 1; i < size; i++) {
            int take = nums[i];
            
            if (i > 1) {
                take += dp[i - 2];
            }
            
            int notTake = dp[i - 1];
            
            dp[i] = max(take, notTake);
            
        }
        
        return dp[size - 1];
    }
};
