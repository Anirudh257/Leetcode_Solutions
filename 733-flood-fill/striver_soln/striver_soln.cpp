class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> res = image;
        int origCol = image[sr][sc];
        
//         int delRow[] = {-1, 1, 0, 0};
//         int delCol[] = {0, 0, -1, 1};
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(image, res, sr, sc, color, origCol, delRow, delCol);
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& res, int row, int col, int color, int origCol, int delRow[], int delCol[]) {
        
        // cout << row << " " << col << endl;
        res[row][col] = color;
        
        int m = image.size(), n = image[0].size();
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && image[newRow][newCol] == origCol && res[newRow][newCol] != color) {
                dfs(image, res, newRow, newCol, color, origCol, delRow, delCol);
            }
            
        }
        
    }
};
