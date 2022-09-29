class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        
        if (nums[0] < nums[size - 1]) {
            return nums[0];
        }
        
        return calcMin(nums, 0, size - 1);
    }
private:
    int calcMin(vector<int>& nums, int l, int r) {        
        while(l < r) {
            int mid = (l + r)/2;
            
            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1] && mid + 1 < nums.size() && nums[mid] < nums[mid + 1]) {
                return nums[mid];
            }
            
            if (nums[l] < nums[r]) {
                if (nums[mid] < nums[r]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if (nums[mid] < nums[l]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            
        }
        return nums[l];
        
    }
};