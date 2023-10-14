// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal = 0;
        int size = nums.size();

        // We need to maximize the value of i and difference between
        // nums[i] and nums[j]
        int maxi = max(nums[0], nums[1]); // Initial value of i
        int maxDiff = nums[0] - nums[1];

        for (int k = 2; k < size; k++) {
            long long val = (long long)maxDiff*nums[k];
            maxVal = max(maxVal, val);

            // As sliding window goes right, k becomes the last value
            // Update difference and maximum i encountered at each step.
            maxDiff = max(maxDiff, maxi - nums[k]); 
            maxi = max(maxi, nums[k]);
        }        

        return maxVal;
    }
};