class Solution {
public:
    // Time complexity: O(mn), Space complexity: O(mn) 
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        
        for (int ind1 = 1; ind1 <= m; ind1++) {
            for (int ind2 = 1; ind2 <= n; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1]) {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        
        return dp[m][n];
    } 
};
