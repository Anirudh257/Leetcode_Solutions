// Time complexity: O(m^2), Space complexity: O(m^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        dp[m - 1] = triangle[m - 1];

        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j], downRight = triangle[i][j];
                down += dp[i + 1][j];
                downRight += dp[i + 1][j + 1];
                dp[i][j] = min(down, downRight);
            }
        }
        return dp[0][0];
    }
};