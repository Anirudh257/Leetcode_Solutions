class Solution {
public:
    // Time complexity: O(mn), Space complexity: O(mn) + Auxiliary space: O(mn)
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int numIsl = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && grid[i][j] == '1') {
                    // cout << i << " " << j << endl;
                    compIslands(grid, i, j, visit, m, n);
                    numIsl++;
                }
            } 
        }
        return numIsl;
    }
private:
    void compIslands(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visit, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || visit[i][j] || grid[i][j] != '1') {
            return;
        }
        visit[i][j] = true;
        
        compIslands(grid, i, j - 1, visit, m, n);
        compIslands(grid, i, j + 1, visit, m, n);
        compIslands(grid, i - 1, j, visit, m, n);
        compIslands(grid, i + 1, j, visit, m, n);
        
    }
};