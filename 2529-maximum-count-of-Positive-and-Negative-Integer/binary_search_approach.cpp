// Time complexity : O(logN), Space complexity: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0, size = nums.size();

        int firstPosInd = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int firstZeroInd = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int numZeros = firstPosInd - firstZeroInd;
        neg = firstPosInd - numZeros;
        pos = size - firstPosInd;

        return max(neg, pos);
    }
};
