// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        int lis = 1;

        for (int i = 0; i < size; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
                lis = max(lis, dp[i]);
            }
        } 
        
        return lis;
    }
};