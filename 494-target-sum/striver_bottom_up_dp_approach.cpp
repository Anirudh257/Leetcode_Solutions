// Time complexity: O(size*target), Space complexity: O(size*target)
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
        vector<vector<int>> dp(size, vector<int>(subSum + 1, 0));

        for (int ind = 0; ind < size; ind++) {
            dp[ind][0] = 1;
        }

        if (nums[0] <= subSum) {
            dp[0][nums[0]] = 1;
        }

        if (nums[0] == 0) { 
            dp[0][0] = 2;
        }

        for (int ind = 1; ind < size; ind++) {
            for (int t = 0; t <= subSum; t++) {
                int notTake = dp[ind - 1][t];
                int take = 0;
                if (t >= nums[ind]) {
                    take = dp[ind - 1][t - nums[ind]];
                }
                dp[ind][t] = take + notTake;                
            }
        }
        return dp[size - 1][subSum];
    }
};