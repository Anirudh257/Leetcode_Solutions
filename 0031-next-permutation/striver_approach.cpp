class Solution {
// Time complexity: O(N), Space complexity: O(1)
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        nums = findNextPerm(nums, size);

        return;
    }
private:
    vector<int> findNextPerm(vector<int>& nums, int size) {
        // Find the breaking point, first i such that a[i] < a[i + 1]
        int ind = -1;
        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // All elements in descending order --> next permutation
        // will be in ascending order.
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        // find smallest number just greater than the dip
        // first number > dip as the remaining array is in ascending order
        for (int i = size - 1; i >= ind; i--)  {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Reverse the remaining numbers from i + 1... end as they are in 
        // descending order
        reverse(nums.begin() + ind + 1, nums.end());

        return nums;
    }
};