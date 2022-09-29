class Solution {
public:
   // Time complexity: O(log N), Space complexity: O(1)
    
    int findMin(vector<int>& nums) {
        int size = nums.size();
        
        if (nums[0] < nums[size - 1]) {
            return nums[0];
        }
        
        return compMinElem(nums, 0, size - 1);
    }
private:
    int compMinElem(vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        while(l <= r) {
            
            if (nums[l] < nums[r]) {
                res = min(nums[l], res);
            }
            
            int mid = (l + r)/2;
            
            res = min(res, nums[mid]);
                        
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return res;
    }
};
