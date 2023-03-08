// Time complexity: O(size*target), Space complexity: O(size*target) + Auxiliary Stack Space: O(target)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();

        if (size == 1) {
            return abs(nums[0]) == abs(target);
        }
        
        // The question can also be rephrased as: finding 2 subsets: (S1 and S2)
        // where S1 - S2 = D and we know S1 + S2 = T
        // S2 =  (T - D)/2
        // We can find all subsets whose sum = (T - D)/2

        int tot = 0;
        for (auto &x : nums) {
            tot += x;
        }

        if (tot - target  < 0 || (tot - target) % 2 != 0) {
            return 0;
        }

        return countSubs(nums, (tot - target)/2);
        
    }
private:
    int countSubs(vector<int>& nums, int subSum) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(subSum + 1, -1));
        return countWays(nums, size - 1, subSum, dp);
    }

    int countWays(vector<int>& nums, int ind, int tar, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (tar == 0 && nums[0] == 0) {
                return 2;
            }
            else if (tar == 0 || nums[ind] == tar) {
                return 1;
            }
            else {
                return 0;
            }
        }

        if (dp[ind][tar] != -1) {
            return dp[ind][tar];
        }

        int notTake = countWays(nums, ind - 1, tar, dp);
        int take = 0;
        if (tar >= nums[ind]) {
            take = countWays(nums, ind - 1, tar - nums[ind], dp);
        }
        return dp[ind][tar] = take + notTake;
    }

};