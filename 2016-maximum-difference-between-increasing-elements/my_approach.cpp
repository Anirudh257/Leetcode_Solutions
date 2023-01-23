// Time complexity: O(N^2), Space complexity: O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1, size = nums.size();

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[j] > nums[i]) {
                    maxDiff = max(maxDiff, (nums[j] - nums[i]));
                }
            }
        }


        return maxDiff;
    }
};
