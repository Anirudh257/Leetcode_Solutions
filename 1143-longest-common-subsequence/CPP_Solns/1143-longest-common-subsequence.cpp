class Solution {
public:
    // Time complexity: O(mn), Space complexity: O(mn) + Auxiliary stack space: O(n + m)  
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return compLCS(text1, text2, m - 1, n - 1, dp);
    } 
private:
    int compLCS(string& text1, string& text2, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (text1[ind1] == text2[ind2]) {
            dp[ind1][ind2] =  1 + compLCS(text1, text2, ind1 - 1, ind2 - 1, dp);
        }
        else {
            dp[ind1][ind2] = max(compLCS(text1, text2, ind1 - 1, ind2, dp), compLCS(text1, text2, ind1, ind2 - 1, dp));        
        }
        
        return dp[ind1][ind2];
    }
};