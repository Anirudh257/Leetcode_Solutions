class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // Time complexity: O(N), Space complexity: O(1)
        int size = nums.size() - 1, numVal = 0;
        
        for (int i = 0; i <= size; i++) {
            if (nums[i] == val) {
                numVal++;
            }
            else {
                nums[i - numVal] = nums[i];
            }
        }
        return size - numVal + 1;
    }
};