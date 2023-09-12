// Time complexity: O(n) on average (good pivot) or O(n^2) in the worst case
// Space complexity: O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
private:
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand()%nums.size()];
        vector<int> left; // elements > pivot 
        vector<int> mid; // elements == pivot
        vector<int> right; // elements < pivot

        for (auto &x : nums) {
            if (x < pivot) {
                right.push_back(x);
            }
            else if (x > pivot) {
                left.push_back(x);
            }
            else {
                mid.push_back(x);
            }
        }
        
        // More than k elements larger in left-half
        if (k <= left.size()) {
            return quickSelect(left, k);
        }   

        // Possible in right-half 
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }

        // Exactly (k - 1) elements < in left-half, kth element = pivot.  
        return pivot;
    }
};