// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> reqRange(2, -1);
        int size = nums.size();

        if (size == 0) {
            return {-1, -1};
        }

        reqRange[0] = searchLeftMost(nums, target, 0, size - 1);
        reqRange[1] = searchRightMost(nums, target, 0, size - 1);

        return reqRange;
    }
private:
    int searchLeftMost(vector<int>& nums, int target, int left, int right) {
        int leftInd = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                leftInd = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return leftInd;
    }
    int searchRightMost(vector<int>& nums, int target, int left, int right) {
        int rightInd = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                rightInd = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return rightInd;
    }

};
