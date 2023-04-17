// Time complexity: O(nm), Space complexity: O(nm) + Auxiliary Stack Space: O(n + m)
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return compNumDistSub(s, t, len1 - 1, len2 - 1, dp);
    }
private:
    int compNumDistSub(string s, string t, int i, int j, vector<vector<int>>& dp) {

        // If entire 2nd string t exhausted, match is found, return 1
        if (j < 0) {
            return 1;
        }

        // If entire 1st string s exhausted and no match found, return 0
        if (i < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }


        // If characters match
        if (s[i] == t[j]) {
                    // shrink string             // ignore this character and check for other
            return dp[i][j] = compNumDistSub(s, t, i - 1, j - 1, dp) + compNumDistSub(s, t, i - 1, j, dp);
        }

        return dp[i][j] = compNumDistSub(s, t, i - 1, j, dp);
    }
};