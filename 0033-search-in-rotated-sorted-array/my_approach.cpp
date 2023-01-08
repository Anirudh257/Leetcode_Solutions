// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
private:
    int search(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int mid = (l + r)/2;
            if (nums[mid] == target) {
                return mid;
            }
            else {
                if (nums[l] <= nums[mid]) {
                    if (target >= nums[l] && target <= nums[mid]) {
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                else {
                    if (target >= nums[mid] && target <= nums[r]) {
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
