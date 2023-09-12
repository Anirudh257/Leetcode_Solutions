// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int a = 1, b = 1, c = 1;

        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;

    }
private:
    int compStairs(int n, vector<int>& dp) {
        if (n <= 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = compStairs(n - 1, dp) + compStairs(n - 2, dp);
    }
};