class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Time complexity: O(nlogn), Space complexity: O(1)
        int len = nums.size();
        int minLen = INT_MAX;
        vector<int> cummSum(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            cummSum[i] = cummSum[i - 1] + nums[i - 1];
        }
        
        for (int i = 1; i <= len; i++) {
            int toFind = target + cummSum[i - 1];
            
            auto bound = lower_bound(cummSum.begin(), cummSum.end(), toFind);
            
            if (bound != cummSum.end()) {
                minLen = min(minLen, static_cast<int>(bound - (cummSum.begin() + i - 1)));
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};
