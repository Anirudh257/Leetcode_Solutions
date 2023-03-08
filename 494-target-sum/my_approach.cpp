// Time complexity: O(size*[target]), Space complexity: O(size*target)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();

        if (size == 1) {
            return abs(nums[0]) == abs(target);
        }
        unordered_map<int, unordered_map<int, int>> dp;
        return countWays(nums, size - 1, target, dp);
    }
private:
    int countWays(vector<int>& nums, int ind, int target, unordered_map<int, unordered_map<int, int>>& dp) {
        if (ind == 0) {
            if (nums[ind] == 0) {
                return 2*(abs(nums[0]) == abs(target));
            }
            else {
                return abs(nums[0]) == abs(target);
            }
        }

        if (dp.find(ind) !=  dp.end() && dp[ind].find(target) != dp[ind].end()) {
            return dp[ind][target];
        }

        int plus = countWays(nums, ind - 1, target - nums[ind], dp);
        int minus = countWays(nums, ind - 1, target + nums[ind], dp);
        
        return dp[ind][target] = plus + minus;
    }
};