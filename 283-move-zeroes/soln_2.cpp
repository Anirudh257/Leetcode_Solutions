class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int size = nums.size();
        int lastNonZeroInd = 0;
        
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroInd++] = nums[i];
            }
        }
        
        for (int i = lastNonZeroInd; i < size; i++) {
            nums[i] = 0;
        }
        
    }
};
