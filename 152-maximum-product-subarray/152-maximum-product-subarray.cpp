class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Time complexity: O(n), Space complexity: O(1)
        int size = nums.size();
        int maxProd = nums[0];
        int currMin = 1, currMax = 1;
        
        for (int n : nums) {
            if (n == 0) {
                currMin = currMax = 1;
                maxProd = max(maxProd, 0);
                continue;
            }
            else {
                int tmpMin = currMin;
                currMin = min({currMin*n, currMax*n, n});
                currMax = max({currMax*n, tmpMin*n, n});
                
            }
            maxProd = max({maxProd, currMax, n});

        }
        
        
        return maxProd;
    }
};