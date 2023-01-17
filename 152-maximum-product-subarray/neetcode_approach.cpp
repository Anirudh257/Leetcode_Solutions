// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for (int n : nums) {
            res = max(res, n);
        }
        int currMax = 1, currMin = 1; // Not 0 as putting 0 kills the product
        for (int n : nums) {
            if (n == 0) {
                currMax = 1, currMin = 1;
            }
            else {
                int tmpMax = currMax*n;
                currMax = max({currMax*n, currMin*n, n});
                currMin = min({tmpMax, currMin*n, n});
                res = max(currMax, res);
            }
        }


        return res;
    }
};
