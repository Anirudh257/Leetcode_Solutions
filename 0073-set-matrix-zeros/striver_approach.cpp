// Time complexity: O(m*n), Space complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, m = matrix.size(), n = matrix[0].size();

        // Using the first rows/columns as marking locations for 0's
        // presence.

        // Location [0][0] signifies 0th row and 0th column that can
        // be confusing. So, using col0 for 0th column.

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // Traversing from back to avoid confusion while marking 0s.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};