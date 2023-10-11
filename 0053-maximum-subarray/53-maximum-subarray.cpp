class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int maxSum = INT_MIN;
        int size = nums.size();
        int curSum = 0;
        
        for (int i = 0; i < size; i++) {
            curSum += nums[i];
            maxSum = max(curSum, maxSum);
            if (curSum < 0) {
                curSum = 0;
            }
            // maxSum = max(curSum, maxSum);
        }
        
        return maxSum;
    }
};