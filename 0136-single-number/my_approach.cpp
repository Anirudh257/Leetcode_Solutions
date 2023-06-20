// Time complexity: O(1), Space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};