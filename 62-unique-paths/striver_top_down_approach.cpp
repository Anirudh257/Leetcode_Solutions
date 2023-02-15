// Time complexity: O(mn), Space complexity: O(mn) + Auxiliary Stack Space: O(m + n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countWays(m - 1, n - 1, dp);
    }
private:
    int countWays(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = countWays(i - 1, j, dp);
        int left = countWays(i, j - 1, dp);

        return dp[i][j] = up + left;
    }
};