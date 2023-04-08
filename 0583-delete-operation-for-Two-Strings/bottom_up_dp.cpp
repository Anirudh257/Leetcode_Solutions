// Time complexity: O(mn), Space complexity: O(mn)
class Solution {
public:
    int minDistance(string word1, string word2) {
       int len1 = word1.length(), len2 = word2.length();
       return len1 + len2 - 2*lcs(word1, word2, len1, len2); 
    }
private:
    int lcs(string& str, string& ptr, int len1, int len2) {
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str[i - 1] == ptr[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[len1][len2];
    }
};