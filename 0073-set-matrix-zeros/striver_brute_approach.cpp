// Time complexity: O(mn), Space complexity: O(m) + O(n), m = #rows, n = #cols
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> isRowMarked(r, 0), isColMarked(c, 0);
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    isRowMarked[i] = 1;
                    isColMarked[j] = 1;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isRowMarked[i] || isColMarked[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};