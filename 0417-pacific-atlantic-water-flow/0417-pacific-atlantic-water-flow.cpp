class Solution {
public:
    
    // Time complexity: O(mn*4*word(size)), Space complexity: O(mn)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, -1));
        vector<vector<int>> atl(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> res;
        for (int j = 0; j < n; j++) {
            pac[0][j] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            pac[i][0] = 1;
        }        
        
        for (int j = 0; j < n; j++) {
            atl[m - 1][j] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            atl[i][n - 1] = 1;
        }        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    perfDFS(visited, i, j, m, n, pac, heights);
                }
            }
        }
        
        vector<vector<bool>> visited2(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited2[i][j] && pac[i][j] == 1) {
                    perfDFS(visited2, i, j, m, n, atl, heights);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atl[i][j] == 1 && atl[i][j] == pac[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    bool perfDFS(vector<vector<bool>>& visited, int i, int j, int m, int n, vector<vector<int>>& wat, vector<vector<int>>& heights) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return false;    
        }
        if (visited[i][j]) {
            if (wat[i][j] == 1) {
                return true;
            }
            else {
                return false;
            }
        }
        
        if (wat[i][j] == 1) {
            return true;
        }
        
        visited[i][j] = true;
        
        int curHt = heights[i][j];
        bool leftAns = false, rightAns = false, upAns = false, downAns = false;
        
        if (j - 1 >= 0 && curHt >= heights[i][j - 1]) {
            leftAns = perfDFS(visited, i, j - 1, m, n, wat, heights);
        }
        
        if (j + 1 < n && curHt >= heights[i][j + 1]) {
            rightAns = perfDFS(visited, i, j + 1, m, n, wat, heights);
        }
        
        if (i - 1 >= 0 && curHt >= heights[i - 1][j]) {
            upAns = perfDFS(visited, i - 1, j, m, n, wat, heights);
        }
        
        if (i + 1 < m && curHt >= heights[i + 1][j]) {
            downAns = perfDFS(visited, i + 1, j, m, n, wat, heights);
        }       
        bool ans = leftAns || rightAns || upAns || downAns;
        visited[i][j] = false;
        
        if (ans) {
            wat[i][j] = 1;
            return true;
        }
        wat[i][j] = 0;
        return false;
    }
};