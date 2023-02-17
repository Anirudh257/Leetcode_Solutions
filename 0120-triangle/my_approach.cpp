// Time complexity: O(m^2), Space complexity: O(m^2) + Auxiliary stack space : O(m)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        return compMin(triangle, 0, 0, dp);
    }
private:
    int compMin(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        int m = triangle.size();
        if (i == m - 1) {
            if (j < m) {
                return triangle[i][j];
            }
            else {
                return INT_MAX;
            }
        }
        if (i < 0 || i == m || j < 0 || j == m) {
            return INT_MAX;
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int down = compMin(triangle, i + 1, j, dp);
        int downRight = compMin(triangle, i + 1, j + 1, dp);

        return dp[i][j] = triangle[i][j] + min(down, downRight);

    }
};