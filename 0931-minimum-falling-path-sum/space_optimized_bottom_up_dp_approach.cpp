// Time complexity: O(mn), Space complexity: O(n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int minRes = 1e9;
        vector<int> cur(n, 1e9), prev(n, 1e9);
        cur = prev = matrix[0];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int upLeft = INT_MAX, up = INT_MAX, upRight = INT_MAX;
                if (i > 0 && j > 0) {
                    upLeft = prev[j - 1];
                }
                if (i > 0) {
                    up = prev[j];
                }
                if (i > 0 && j <= n - 2) {
                    upRight = prev[j + 1];
                }
                cur[j] = matrix[i][j] + min({upLeft, up, upRight});
            }
            prev = cur;
        }

        for (int j = 0; j < n; j++) {
            minRes = min(minRes, prev[j]);
        }

        return minRes;
    }
};