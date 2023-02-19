// Time complexity: O(mn), Space complexity: O(mn) + Auxiliary Stack Space: O(m)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int minRes = 1e9;
        vector<vector<int>> dp(m, vector<int>(n, 1e9));

        for (int j = 0; j < n; j++) {
            minRes = min(minRes, compMinSum(matrix, m - 1, j, dp));
        }
        return minRes;
    }
private:
    int compMinSum(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        int m = matrix.size(), n = matrix[0].size();
        if (i == 0 && j >= 0 && j < n) {
            return matrix[i][j];
        }
        if (i < 0 || j < 0 || j >= n) {
            return 1e9;
        }
        if (dp[i][j] != 1e9) {
            return dp[i][j];
        }

        int upLeft = compMinSum(matrix, i - 1, j - 1, dp);
        int up = compMinSum(matrix, i - 1, j, dp);
        int upRight = compMinSum(matrix, i - 1, j + 1, dp);

        return dp[i][j] = matrix[i][j] + min({upLeft, up, upRight});
    }
};