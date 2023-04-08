// Time complexity: O(n^2), Space complexity: O(n^2) + Auxiliary Stack Space: O(n)
class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        return compInsertions(s, 0, len - 1, dp);
    }
private:
    int compInsertions(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int numInsert = 0;
        if (s[i] == s[j]) {
            numInsert = compInsertions(s, i + 1, j - 1, dp);
        }
        else {
            numInsert = 1 + min(compInsertions(s, i + 1, j, dp), compInsertions(s, i, j - 1, dp));
        }    
        return dp[i][j] = numInsert;

    }
};