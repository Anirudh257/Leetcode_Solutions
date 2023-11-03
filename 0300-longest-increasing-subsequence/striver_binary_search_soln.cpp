// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> lis = {nums[0]};
        int len = 1;
        for (int i = 1; i < size; i++) {
            // Find the index where nums[i] should be placed.
            int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if (ind == lis.size()) {
                lis.push_back(nums[i]);
                len++;
            }
            else {
                lis[ind] = nums[i];
            }
        }

        // avoid doing temp.size() to save computation.
        return len;
    }
};