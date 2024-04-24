// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();

        return search(nums, target, 0, size - 1);
    }
private:
    bool search(vector<int>& nums, int& target, int low, int high) {
        int mid;

        while (low <= high) {
            mid = low + (high - low)/2;

            if (nums[mid] == target) {
                return true;
            }
            // Edge case:
            // When nums[low] == nums[mid] == nums[high]
            // We can't definitely say if either half is sorted, so trim space
            else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            else {
                if (nums[low] <= nums[mid]) {
                    if (nums[low] <= target && target <= nums[mid]) {
                        high = mid - 1;
                    }
                    else {
                        return search(nums, target, mid + 1, high);
                    }
                }
                else if (nums[mid] <= nums[high]) {
                    if (nums[mid] <= target && target <= nums[high]) {
                        low = mid + 1;
                    }
                    else {
                        return search(nums, target, low, mid - 1);
                    }
                }
            }
        } 
 

        return false;
    }
};