// Time complexity: O(mn), Space complexity: O(mn) + Auxiliary Stack Space: O(m + n)
class Solution {
public:
    int minDistance(string word1, string word2) {
       int len1 = word1.length(), len2 = word2.length();
       vector<vector<int>> dp(len1, vector<int>(len2, -1));
       return len1 + len2 - 2*lcs(word1, word2, len1 - 1, len2 - 1, dp); 
    }
private:
    int lcs(string& str, string& ptr, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (str[i] == ptr[j]) {
            return dp[i][j] = 1 + lcs(str, ptr, i - 1, j - 1, dp);
        }
        else {
            return dp[i][j] = max(lcs(str, ptr, i, j - 1, dp), lcs(str, ptr, i - 1, j, dp));
        }
    }

};