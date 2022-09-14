class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int maxDiff = -1;
       int minVal = nums[0]; 
       int size = nums.size();
        
       for (int i = 1; i < size; i++) {
           int diff = nums[i] - minVal;
           minVal = min(minVal, nums[i]);
           maxDiff = max(maxDiff, diff);
       }
        
       return maxDiff <= 0 ? -1 : maxDiff;
    }
};