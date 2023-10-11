// Time complexity: O(NlogN), Space complexity: O(log N) stack calls.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxSum = divAndConq(nums, 0, size - 1);
        return maxSum;
    }
private:
    int divAndConq(vector<int>& nums, int st, int end) {
        if (st > end) {
            return INT_MIN;
        }
        if (st == end) {
            return nums[st];
        }
        int mid = st + (end - st)/2;
        int bestLeftSum = 0, bestRightSum = 0, currSum = 0;

        for (int i = mid - 1; i >= st; i--) {
            currSum += nums[i];
            bestLeftSum = max(bestLeftSum, currSum);
        }
        currSum = 0;
        for (int i = mid + 1; i <= end; i++) {
            currSum += nums[i];
            bestRightSum = max(bestRightSum, currSum);
        }

        int bestCombSum = bestLeftSum + nums[mid] + bestRightSum;

        int leftMaxSum = divAndConq(nums, st, mid - 1);
        int rightMaxSum = divAndConq(nums, mid + 1, end);

        return max({leftMaxSum, rightMaxSum, bestCombSum});

    }
};