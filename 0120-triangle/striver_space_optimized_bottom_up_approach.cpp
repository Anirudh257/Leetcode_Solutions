// Time complexity: O(m^2), Space complexity: O(m)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // vector<vector<int>> dp(m, vector<int>(m, 0));
        vector<int> cur(m, 0), next(m, 0);

        next = cur = triangle[m - 1];


        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j], downRight = triangle[i][j];
                down += next[j];
                downRight += next[j + 1];
                cur[j] = min(down, downRight);
            }
            next = cur;
        }
        return cur[0];
    }
};