class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // Time complexity: O(m*n), Space complexity: O(m*n)
        int i = 0, j = 0, m = mat.size(), n = mat[0].size();
        
        vector<int> finOrd(n*m);
        finOrd[0] = mat[0][0];
        int count = 1;
        
        bool isUpRight = true;
        
        while (i != m - 1 || j != n - 1) {
            if (isUpRight) {
                if (j == n - 1) {
                    i++;
                    isUpRight = false;
                }
                else if (i == 0) {
                    j++;
                    isUpRight = false;
                }
                else {
                    i--;
                    j++;
                }
            }
            else {
                if (i == m - 1) {
                    j++;
                    isUpRight = true;
                }
                else if (j == 0) {
                    i++;
                    isUpRight = true;
                }
                else {
                    i++;
                    j--;
                }
            }
            finOrd[count++] = mat[i][j];
        }
        
        return finOrd;
    }
};
