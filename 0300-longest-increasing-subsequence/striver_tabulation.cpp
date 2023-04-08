// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lisLen = 1;        
        int size = nums.size();
        vector<int> dp(size, 1);
        for (int i = 0; i < size; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
                lisLen = max(lisLen, dp[i]);
            }
        }
        return lisLen;
    }
};