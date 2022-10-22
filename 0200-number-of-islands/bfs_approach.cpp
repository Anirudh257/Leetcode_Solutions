class Solution {
public:
    // Time complexity: O(mn), Space complexity: O(min(m,n)) Queue expands only till the min of the edges. 
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int numIsl = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && grid[i][j] == '1') {
                    numIsl++;
                    queue<pair<int, int>> neigh;
                    neigh.push({i, j});
                    // visit[i][j] = 
                    
                    while(!neigh.empty()) {
                        auto rc = neigh.front();
                        neigh.pop();
                        int r = rc.first, c = rc.second;
                        
                        visit[r][c] = true;
                        
                        if (r - 1 >= 0 && !visit[r - 1][c] && grid[r - 1][c] == '1') {
                            neigh.push({r - 1, c});
                            visit[r - 1][c] = true;
                        }
                        if (r + 1 < m && !visit[r + 1][c] && grid[r + 1][c] == '1') {
                            neigh.push({r + 1, c});
                            visit[r + 1][c] = true;
                        }
                        if (c - 1 >= 0 && !visit[r][c - 1] && grid[r][c - 1] == '1') {
                            neigh.push({r, c - 1});
                            visit[r][c - 1] = true;
                        }
                        if (c + 1 < n && !visit[r][c + 1] && grid[r][c + 1] == '1') {
                            neigh.push({r, c + 1});
                            visit[r][c + 1] = true;
                        }                        
                    }
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
