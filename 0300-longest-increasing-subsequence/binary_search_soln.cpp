// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> lis = {nums[0]};

        for (int i = 1; i < size; i++) {
            int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if (ind == lis.size()) {
                lis.push_back(nums[i]);
            }
            else {
                lis[ind] = nums[i];
            }
        }

        return lis.size();
    }
};