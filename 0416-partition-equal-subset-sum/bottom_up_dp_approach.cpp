// Time complexity: O(n*sum/2), Space complexity: O(n*sum/2)  
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
        int reqSum = (int)sum/2;

        vector<vector<bool>> dp(size, vector<bool>(reqSum + 1, 0));

        // Base case: sum == 0
        for (int i = 0; i < size; i++) {
            dp[i][0] = true;
        }

        // Base case: ind = 0
        if (nums[0] <= reqSum) {
            dp[0][nums[0]] = dp[0][nums[0]] = true;
        }

        
        for (int ind = 1; ind < size; ind++) {
            for (int tar = 1; tar <= reqSum; tar++) {
                bool notTake = dp[ind - 1][tar];
                bool take = false;
                if (tar >= nums[ind]) {
                    take = dp[ind - 1][tar - nums[ind]];
                }
                dp[ind][tar] = take || notTake;

            }
        }
        return dp[size - 1][reqSum];
    }
};