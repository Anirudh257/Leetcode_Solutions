// Time complexity: O(n*sum/2), Space complexity: O(sum/2)  
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

        vector<bool> prev(reqSum + 1, 0), curr(reqSum + 1, 0);
        // vector<vector<bool>> dp(size, vector<bool>(reqSum + 1, 0));

        // Base case: sum == 0
        prev[0] = curr[0] = true;

        // Base case: ind = 0
        if (nums[0] <= reqSum) {
            prev[nums[0]] = curr[nums[0]] = true;
        }
        
        for (int ind = 1; ind < size; ind++) {
            for (int tar = 1; tar <= reqSum; tar++) {
                bool notTake = prev[tar];
                bool take = false;
                if (tar >= nums[ind]) {
                    take = prev[tar - nums[ind]];
                }
                curr[tar] = take || notTake;
            }
            prev = curr;
        }
        return prev[reqSum];
    }
};