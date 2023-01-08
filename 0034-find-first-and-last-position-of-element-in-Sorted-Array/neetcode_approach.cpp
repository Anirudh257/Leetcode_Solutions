// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> reqRange(2, -1);
        int size = nums.size();

        if (size == 0) {
            return {-1, -1};
        }

        reqRange[0] = binSearch(nums, target, 0, size - 1, true);
        reqRange[1] = binSearch(nums, target, 0, size - 1, false);

        return reqRange;
    }
private:
    int binSearch(vector<int>& nums, int target, int left, int right, bool leftBias) {
        int reqInd = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                if (leftBias) {
                    // Keep going left
                    right = mid - 1;
                }
                else {
                    // Keep going right
                    left = mid + 1;
                }
                reqInd = mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return reqInd;
    }
};
