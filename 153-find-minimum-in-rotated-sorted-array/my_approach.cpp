// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }
        if (nums[0] < nums.back()) {
            return nums[0];
        }

        return binSearch(nums, 0, size - 1);
    }
private:
    int binSearch(vector<int>& nums, int l, int r) {

        while(l <= r) {
            int m = l + (r - l)/2;
            if (nums[m + 1] < nums[m]) {
                return nums[m + 1];
            }
            else if (nums[l] < nums[m]) {
                l = m;
            }
            else {
                r = m;
            }
        }

        return 0;
    }
};
