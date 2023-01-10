// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int l = 0, r = size - 1;
        while(l < r) {
            int m = (l + r + 1)/2; // To avoid underflow case in comparison
            if (nums[m] > nums[m - 1]) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return l;
    }
};
