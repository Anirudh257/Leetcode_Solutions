// Time complexity: O(mn^2)*9, Space complexity: O(mn^2) + Auxiliary Stack Space: O(n) m = number of rows,
// n = number of columns.
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return compCherries(grid, dp, 0, 0, n - 1, m, n);
    }
private:
    int compCherries(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2, int m, int n) {
        if (i == m) {
            return 0;
        }

        if (i < 0 || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return INT_MIN;
        }

        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int dd = compCherries(grid, dp, i + 1, j1, j2, m, n);
        int dl = compCherries(grid, dp, i + 1, j1, j2 - 1, m, n);
        int dr = compCherries(grid, dp, i + 1, j1, j2 + 1, m, n);

        int ld = compCherries(grid, dp, i + 1, j1 - 1, j2, m, n);
        int ll = compCherries(grid, dp, i + 1, j1 - 1, j2 - 1, m, n);
        int lr = compCherries(grid, dp, i + 1, j1 - 1, j2 + 1, m, n);

        int rd = compCherries(grid, dp, i + 1, j1 + 1, j2, m, n);
        int rl = compCherries(grid, dp, i + 1, j1 + 1, j2 - 1, m, n);
        int rr = compCherries(grid, dp, i + 1, j1 + 1, j2 + 1, m, n);

        if (j1 == j2) {
            dp[i][j1][j2] = grid[i][j1];
        }
        else {
            dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }

        return dp[i][j1][j2] += max({dd, dl, dr, ld, ll, lr, rd, rl, rr});
    }
};