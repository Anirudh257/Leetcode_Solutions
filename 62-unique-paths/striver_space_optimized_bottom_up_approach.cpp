// Time complexity: O(mn), Space complexity: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0), cur(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    cur[j] = 1;
                }
                else {
                    int up = 0, left = 0;
                    if (i > 0) {
                        up = prev[j];
                    }
                    if (j > 0) {
                        left = cur[j - 1];
                    }
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }

        return prev[n - 1];
    }
};