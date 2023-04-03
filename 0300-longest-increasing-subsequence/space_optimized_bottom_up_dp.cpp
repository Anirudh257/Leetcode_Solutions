// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> prev(size + 2, 0), curr(size + 2, 0);

        for (int ind = 1; ind <= size; ind++) {
            for (int prevInd = 1; prevInd <= size + 1; prevInd++) {
                int take = 0, notTake = 0;
                if (prevInd == size + 1) {
                    take = 1 + prev[ind];
                    notTake = prev[prevInd];
                }
                else {
                    if (nums[ind - 1] < nums[prevInd - 1]) {
                        take = 1 + prev[ind];
                    }
                    notTake = prev[prevInd];
                }
                curr[prevInd] = max(take, notTake);
            }
            prev = curr;
        }

        return curr[size + 1];
    }
};