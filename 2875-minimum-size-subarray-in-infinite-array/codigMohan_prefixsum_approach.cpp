// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        // Build prefix sum while we traverse the array
        unordered_map<long, int>   prefSum {{0L, -1}};
        int size = nums.size(), minLen = INT_MAX;
        long long curSum = 0;
        long long totSum = accumulate(nums.begin(), nums.end(), 0L);
        int k = target/totSum;
        target %= totSum;

        if (target == 0) {
            return k*size;
        }

        for (int i = 0; i < 2*size; i++) {
            curSum += nums[i%size];
            if (prefSum.count(curSum - target)) {
                minLen = min(minLen, i - prefSum[curSum - target]);
            }
            prefSum[curSum] = i;
        }

        return minLen < size ? minLen + k*size : -1;

    }
};