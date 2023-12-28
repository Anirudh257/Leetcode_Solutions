// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int, int> freq;

        for (int r = 0; r < size; r++) {
            freq[nums[r]]++;
            while (freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};