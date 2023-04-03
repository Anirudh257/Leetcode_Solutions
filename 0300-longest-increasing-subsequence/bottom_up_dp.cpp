// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size + 1, vector<int>(size + 2, 0));

        for (int ind = 1; ind <= size; ind++) {
            for (int prevInd = 1; prevInd <= size + 1; prevInd++) {
                int take = 0, notTake = 0;
                if (prevInd == size + 1) {
                    take = 1 + dp[ind - 1][ind];
                    notTake = dp[ind - 1][prevInd];
                }
                else {
                    if (nums[ind - 1] < nums[prevInd - 1]) {
                        take = 1 + dp[ind - 1][ind];
                    }
                    notTake = dp[ind - 1][prevInd];
                }
                dp[ind][prevInd] = max(take, notTake);
            }
        }

        return dp[size][size + 1];
    }
};