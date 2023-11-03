// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lisLen = 1, lastInd = 0;        
        int size = nums.size();
        vector<int> dp(size, 1);
        vector<int> hash(size, 0);

        for (int i = 0; i < size; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev] && dp[i] < 1 + dp[prev]) {
                    hash[i] = prev;
                    dp[i] = 1 + dp[prev];
                }
                if (lisLen < dp[i]) {
                    lisLen = dp[i];
                    lastInd = i;
                }
            }
        }
        vector<int> lis;
        // lis.push_back(nums[lastInd]);

        while(hash[lastInd] != lastInd) {
            lis.push_back(nums[lastInd]);
            lastInd = hash[lastInd];
        }
        lis.push_back(nums[lastInd]);

        reverse(lis.begin(), lis.end());

        return lisLen;
    }
};