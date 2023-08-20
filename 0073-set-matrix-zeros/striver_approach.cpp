class Solution {
public:
// Time complexity: O(2*m*n), Space complexity: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        // col0 to check if any element in the 0th row or 0th column is 
        // set to 0.
        int col0 = 1, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            // Using 1st element of row and 1st element of column as
            // flag
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

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