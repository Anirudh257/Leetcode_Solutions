// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int minLen = INT_MAX, curLen = 0;

        // Storing a cummulative sum to reduce repeated check of target in nums
        vector<int> cummSum(size + 1, 0);

        for (int i = 1; i <= size; i++) {
            cummSum[i] = cummSum[i - 1] + nums[i - 1];
        }    

        for (int i = 1; i <= size; i++) {
            int search = target + cummSum[i - 1];
            
            // Find the sum >= search
            auto bound = lower_bound(cummSum.begin(), cummSum.end(), search);
            if (bound != cummSum.end()) {
                curLen = static_cast<int>(bound - (cummSum.begin() + i - 1));
            }

            minLen = min(minLen, curLen);

        }

        return minLen != INT_MAX ? minLen : 0;
    }
};