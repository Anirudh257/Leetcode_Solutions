class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        
        int left = 0, right = size - 1;
        
        for (int i = size - 1; i >= 0; i--) {
            int sq;
            if (abs(nums[left]) > abs(nums[right])) {
                sq = nums[left];
                left++;
            }
            else {
                sq = nums[right];
                right--;
            }
            res[i] = sq*sq;
        }
        
        return res;
    }
};
