class Solution {
public:
    // Time complexity: O(N), Space complexity: O(1)
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if (size < 2) {
            return size ? nums[0] : 0;
        }
        
        return max(maxAmtComp(nums, 0, size - 2), maxAmtComp(nums, 1, size - 1));
    }
private:
    int maxAmtComp(vector<int>& nums, int l, int r) {
        int temp = 0, prev = 0, cur = 0;
        
        for (int i = l; i <= r; i++) {
            temp = max(nums[i] + prev, cur);
            prev = cur;
            cur = temp;
        }
        
        return cur;
    }
};
