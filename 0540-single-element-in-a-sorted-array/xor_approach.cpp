// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        int size = nums.size();

        for (int i = 1; i < size; i++) {
            res ^= nums[i];
        }
        return res;
    }
};