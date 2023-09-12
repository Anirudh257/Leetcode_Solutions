// Time complexity: O(n), Space complexity: O(n) 
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        vector<int> temp1, temp2;

        for (int i = 0; i < size; i++) {
            if (i != 0) {
                temp1.push_back(nums[i]);
            }
            if (i != size - 1) {
                temp2.push_back(nums[i]);
            }
        }

        return max(compMaxAmt(temp1), compMaxAmt(temp2)); 
    }
private:
    int compMaxAmt(vector<int>& temp) {
        int size = temp.size();
        vector<int> dp(size, 0);

        dp[0] = temp[0];

        for (int i = 1; i < size; i++) {
            int take = temp[i];

            if (i > 1) {
                take += dp[i - 2];
            }
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }

        return dp[size - 1];
    }
};