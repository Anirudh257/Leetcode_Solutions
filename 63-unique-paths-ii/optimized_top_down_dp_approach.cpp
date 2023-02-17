// Time complexity: O(mn), Space complexity: O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> curRow(n, 0), prev(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i>= 0 & j>= 0 && obstacleGrid[i][j] == 1) {
                    curRow[j] = 0;
                }
                else if (i == 0 && j == 0) {
                    curRow[j] = 1;
                }
                else {
                    int up = 0, left = 0;
                    if (j - 1 >= 0) {
                        left = curRow[j - 1];
                    }
                    if (i - 1 >= 0) {
                        up = prev[j];
                    }
                    curRow[j] = up + left;
                }
            }
            prev = curRow;
        }

        return prev[n - 1];
    }
};