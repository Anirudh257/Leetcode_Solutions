// Time complexity: O(MN), Space complexity: O(MN) + Auxiliary Space complexity: O(M - 1 + N - 1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return compMinPath(grid, 0, 0, m, n, 0, dp);
    }
private:
    int compMinPath(vector<vector<int>>& grid, int i, int j, int m, int n, int cost, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1e9;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        return dp[i][j] = grid[i][j] + min(compMinPath(grid, i + 1, j, m, n, cost, dp), compMinPath(grid, i, j + 1, m, n, cost,dp));

    }
};
