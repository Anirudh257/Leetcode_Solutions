// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Follow up approach for infinite stream
        int size = nums.size(), left = 0, right = 0, zeroInd = -1, maxLen = 0;

        while (right < size) {
            if (nums[right] == 0) {
                left = zeroInd + 1;
                zeroInd = right;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
