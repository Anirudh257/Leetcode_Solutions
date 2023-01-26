// Time complexity: O(MN), Space complexity: O(N)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> curr(n, 0), prev(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
        
                }
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0) {
                        up = prev[j];
                    }
                    if (j > 0) {
                        left = curr[j - 1];
                    }
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
