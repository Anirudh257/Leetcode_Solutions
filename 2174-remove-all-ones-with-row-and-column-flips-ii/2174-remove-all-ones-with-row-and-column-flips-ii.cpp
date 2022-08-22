class Solution {
public:
    // Time complexity: O(n*m)*max(m, n), Space complexity: O(m + n)
    int removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowVals(n, 0), colVals(m, 0);
        int minFlips = INT_MAX;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }
                
                for (int r = 0; r < m; r++) {
                    colVals[r] = grid[r][col];
                    grid[r][col] = 0;
                }
                for (int c = 0; c < n; c++) {
                    rowVals[c] = grid[row][c];
                    grid[row][c] = 0;
                }
                
                minFlips = min(minFlips, 1 + removeOnes(grid));

                for (int c = 0; c < n; c++) {
                    grid[row][c] = rowVals[c];
                }
                
                for (int r = 0; r < m; r++) {
                    grid[r][col] = colVals[r];
                }
                

            }
        }
        
        
        return ((minFlips == INT_MAX) ? 0 : minFlips);
    }
};