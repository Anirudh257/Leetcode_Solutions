class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int maxSum = 0;
        int l = 0, r = 0, minLen = INT_MAX;
        int len = nums.size();
        int currSum = 0;
        bool flag = false;
        
        while(r < len) {
            
            currSum += nums[r];
            
            while(currSum >= target) {
                flag = true;
                currSum -= nums[l];
                minLen = min(minLen, r - l + 1);
                l++;
            }
            
            r++;
        }
                
        
        if (!flag) {
            return 0;
        }
        
        return minLen;
    }
};