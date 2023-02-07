// Time complexity: O(mn^2*9) 9 states, Space complexity: O(mn^2) m = number of rows, n = number of columns
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        // Base case
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                if (j1 == j2) {
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                }
                else {
                    dp[m - 1][j1][j2] += grid[m - 1][j1] + grid[m - 1][j2];
                }
            }
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    int maxScore = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int val = grid[i][j1];
                            if (j1 != j2) {
                                val += grid[i][j2];
                            }
                            if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n) {
                                val += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            else {
                                val += -1e8;
                            }
                            maxScore = max(maxScore, val);
                        }
                    }
                    dp[i][j1][j2] = maxScore;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};