// Time complexity: O(mn), Space complexity: O(mn) + Auxiliary Stack Space: O(m + n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(obstacleGrid, m - 1, n - 1, dp);
    }
private:
    int countPaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (i == 0 && j == 0) {
            return obstacleGrid[i][j] != 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int left = countPaths(obstacleGrid, i, j - 1, dp);
        int up = countPaths(obstacleGrid, i - 1, j, dp);

        return dp[i][j] = left + up;

    }
};