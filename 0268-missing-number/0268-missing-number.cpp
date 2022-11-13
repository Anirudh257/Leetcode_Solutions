class Solution {
public:
    // Time complexity: O(N), Space complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int reqSum = (n*(n + 1))/2;
        
        int sum = 0;
        
        for (auto &x : nums) {
            sum += x;
        }
        
        return reqSum - sum;
    }
};