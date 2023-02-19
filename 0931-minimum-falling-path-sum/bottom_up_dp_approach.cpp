// Time complexity: O(mn), Space complexity: O(mn)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int minRes = 1e9;
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        dp[0] = matrix[0];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int upLeft = INT_MAX, up = INT_MAX, upRight = INT_MAX;
                if (i > 0 && j > 0) {
                    upLeft = dp[i - 1][j - 1];
                }
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                if (i > 0 && j <= n - 2) {
                    upRight = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + min({upLeft, up, upRight});
            }
        }

        for (int j = 0; j < n; j++) {
            minRes = min(minRes, dp[m - 1][j]);
        }

        return minRes;
    }
};