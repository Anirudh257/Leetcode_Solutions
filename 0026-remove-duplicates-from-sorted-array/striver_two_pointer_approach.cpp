// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        int f = 0, s = 1;

        for (int s = 1; s < size; s++) {
            if (nums[f] != nums[s]) {
                f++;
                nums[f] = nums[s];
            }
        }
        return f + 1;
    }
};