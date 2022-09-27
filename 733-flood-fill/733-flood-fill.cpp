class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        // Time complexity: O(mn), Space complexity: O(1)
        fillColor(sr, sc, m, n, color, image[sr][sc], image);
        
        return image;
    }
private:
    void fillColor(int i, int j, int m, int n, int color, int prevColor, vector<vector<int>>& image) {
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != prevColor) {
            return;
        }
        image[i][j] = -1;
        
        fillColor(i, j - 1, m, n, color, prevColor, image);
        fillColor(i, j + 1, m, n, color, prevColor, image);
        fillColor(i - 1, j, m, n, color, prevColor, image);
        fillColor(i + 1, j, m, n, color, prevColor, image);
        
        
        image[i][j] = color;
    }
};