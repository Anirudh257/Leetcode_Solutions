class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // Time complexity: O(m*n), Space complexity: O(m*n)
         int m = mat.size(), n = mat[0].size();
         vector<int> finOrd;

         for (int d = 0; d <= m + n - 2; d++) {
              for (int x = 0; x <= d; x++) {
                    int i = x;
                    int j = d - i;
                    
                    if (d % 2 == 0) {
                        swap(i, j);
                    }

                    if (i >= m || j >= n) {
                        continue;
                    }                    

                    finOrd.push_back(mat[i][j]);
              }
         }
         return finOrd;
    }
};
