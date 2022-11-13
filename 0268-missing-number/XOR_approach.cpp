class Solution {
public:
    // Time complexity: O(N), Space complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int expXor = 0;
        int n = nums.size();
        
        for (int i = 0; i <= n; i++) {
            expXor ^= i;
        }
        int actXor = 0;
        for (int num : nums) {
            actXor ^= num;
        }
        
        return actXor ^ expXor;
    }
};
