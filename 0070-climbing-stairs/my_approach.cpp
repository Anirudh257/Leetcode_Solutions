// Time complexity: O(N), Space complexity: O(N) + Auxiliary Stack Space of O(N)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        dp[2] = 2;
        return compStairs(dp, n);
    }
private:
    int compStairs(vector<int>& dp, int n) {
        if (n == 0) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = compStairs(dp, n - 1) + compStairs(dp, n - 2);
    }
};