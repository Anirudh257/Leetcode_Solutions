class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int size = nums.size();
        int j = 0;
        
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                continue;
            }
            else {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
    }
};