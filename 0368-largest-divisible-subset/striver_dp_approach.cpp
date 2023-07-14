class Solution {
public:
// Time complexity: O(n^2), Space complexity: O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        vector<int> hash(size, 1);

        // Sorting to make condition checking easier, only check
        // nums[j] % nums[i], j > i
        // Reduces to a Longest increasing subsequence problem.
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i++) {
            hash[i] = i;
            for (int prevInd = 0; prevInd < i; prevInd++) {
                if (nums[i] % nums[prevInd] == 0 && 1 + dp[prevInd] > dp[i]) {

                    dp[i] = 1 + dp[prevInd];
                    hash[i] = prevInd;
                }
            }
        }

        int lastInd = -1, ans = -1;
        for (int i = 0; i < size; i++) {
            if (dp[i] > ans) {
                ans = dp[i];
                lastInd = i;
            }
        }

        vector<int> res = {nums[lastInd]};

        while(hash[lastInd] != lastInd) {
            lastInd = hash[lastInd];
            res.push_back(nums[lastInd]);
        }

        reverse(res.begin(), res.end());

        return res;

    }
};