class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Time complexity: O(N), Space complexity: O(1)
        int i = 0,j = 0, size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
