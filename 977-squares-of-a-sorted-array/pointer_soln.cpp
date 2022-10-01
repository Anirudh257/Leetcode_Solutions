class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        // Time complexity: O(N), Space complexity: O(1)
        vector<int> res(size);
        int left = 0, right = size - 1, val = 0;
        
        for (int i = size - 1; i >= 0; i--) {
            if (abs(nums[left]) < abs(nums[right])) {
                val = nums[right];
                right--;
            }
            else {
                val = nums[left];
                left++;
            }
            res[i] = val*val;
        }
        
        
        return res;
        
    }
};
