// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        // vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
        vector<int> curr(size + 1, 0);
        vector<int> next(size + 1, 0);

        for (int ind = size - 1; ind >= 0; ind--) {
            for (int prevInd = ind -1; prevInd >= -1; prevInd--) {
                int take = 0, notTake = 0;
                if (prevInd == -1 || nums[prevInd] < nums[ind]) {
                    take = 1 + next[ind + 1];
                }
                notTake = next[prevInd + 1];
                curr[prevInd + 1] = max(take, notTake); 
            }
            next = curr;
        }

        return next[-1 + 1];
    }
};