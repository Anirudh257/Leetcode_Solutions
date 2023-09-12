// Time complexity: O(logN), Space complexity: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int low = 0, high = size - 2; // Keeping it as size-2 to avoid 
        // missing numbers at the last place.

        while (low <= high) {
            int mid = (low + high) >> 1;

            // even ^ 1 = immediately following odd number
            // odd ^ 1 = immediately preceding even number
            // If this is equal,the left half is fine and required number
            // in right half, else check left half
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return nums[low];

        // 1st instance = even index
        // 2nd instance = odd index 
        // If this pattern is incorrect, the single number is in the half.
    }
};