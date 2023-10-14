// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int l = 0, r = 0, sum = 0, minSubLen = INT_MAX;

        while(r < size) {
            sum += nums[r];
            r++;
            while (sum >= target) {
                sum -= nums[l];
                l++;
                minSubLen = min(minSubLen, r - l + 1);
            }
        }
        return minSubLen == INT_MAX ? 0 : minSubLen;
    }
};