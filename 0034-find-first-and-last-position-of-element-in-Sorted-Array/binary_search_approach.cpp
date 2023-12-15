// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int lbInd = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lbInd == size || nums[lbInd] != target) {
            return {-1, -1};
        }

        int l = lbInd + 1, h = size - 1, lastInd = lbInd;

        while(l <= h) {
            int mid = l + (h - l)/2;
            if (nums[mid] == target) {
                lastInd = mid;
                l = mid + 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return {lbInd, lastInd};
    }
};