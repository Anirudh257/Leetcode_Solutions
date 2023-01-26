// Time complexity: O(MN), Space complexity: O(MN)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0) {
                        up = dp[i - 1][j];
                    }
                    if (j > 0) {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
private:
    int compMinPath(vector<vector<int>>& grid, int i, int j, int m, int n,vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1e9;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i == 0 && j == 0) {
            return grid[i][j];
        }

        int up = compMinPath(grid, i - 1, j, m, n, dp);
        int left = compMinPath(grid, i , j - 1, m, n, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
};
