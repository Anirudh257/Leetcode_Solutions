// Time complexity: O(mn^2*9) 9 states, Space complexity: O(mn^2) + Auxiliary Stack Space : O(n)
// m = number of rows, n = number of columns
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));


        // return dp[m - 1][]
        return compCherries(grid, dp, 0, 0, n - 1, m, n);
    }
private:
    int compCherries(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2, int m, int n) {
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e8;
        }

        if (i == m - 1) {
            if (j1 != j2) {
                return grid[i][j1] + grid[i][j2];
            }
            else {
                return grid[i][j1];
            }
        }

        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int maxScore = -1e8;
        // Explore all paths using for loop
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int val = grid[i][j1];
                if (j1 != j2) {
                    val += grid[i][j2];
                }
                val += compCherries(grid, dp, i + 1, j1 + dj1, j2 + dj2, m, n);
                maxScore = max(maxScore, val);
            }
        }

        return dp[i][j1][j2] = maxScore;
    }
};