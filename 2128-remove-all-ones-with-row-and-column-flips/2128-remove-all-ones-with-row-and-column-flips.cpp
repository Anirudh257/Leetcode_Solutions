class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == 1) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};