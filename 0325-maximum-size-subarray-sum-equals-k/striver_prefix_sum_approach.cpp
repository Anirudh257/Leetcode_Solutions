// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<long long int, int> prefMap;
        long long int curSum = 0;
        int maxSubLen = INT_MIN;

        for (int i = 0; i < size; i++) {
            curSum += nums[i];
            if (curSum == k) {
                maxSubLen = max(maxSubLen, i + 1);
            }

            long long int remSum = curSum - k;
            if (prefMap.find(remSum) != prefMap.end()) {
                int lastInd = prefMap[remSum];
                maxSubLen = max(maxSubLen, i - lastInd);
            }

            if (prefMap.find(curSum) == prefMap.end()) {
                prefMap[curSum] = i;
            }
        }

        return maxSubLen == INT_MIN ? 0 : maxSubLen;
    }
};