// Time complexity: O(nm), Space complexity: O(nm) + Auxiliary Stack Space: O(mn)
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<int>> dp(sLen, vector<int>(pLen, -1));
        return compMatch(s, p, sLen - 1, pLen - 1, dp);
    }
private:
    int compMatch(string& s, string& p, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind1 < 0 && ind2 < 0) {
            return 1; // All characters matched
        }

        if (ind1 >= 0 && ind2 < 0) {
            return 0; // Pattern unable to match remaining characters
        }

        if (ind1 < 0 && ind2 >= 0) {
            // If the pattern contains all stars, then match is possible
            for (int i = 0; i <= ind2; i++) {
                char ch = p[i];
                if (ch != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        
        if (s[ind1] == p[ind2] || p[ind2] == '?') {
            return dp[ind1][ind2] = compMatch(s, p, ind1 - 1, ind2 - 1, dp);
        }
        else if (p[ind2] == '*') {
            bool match = compMatch(s, p, ind1 - 1, ind2, dp); // match current character
            // and extend * matching sequence.
            bool noMatch = compMatch(s, p, ind1, ind2 - 1, dp); // Match 0 character;
            return dp[ind1][ind2] = match || noMatch;
        }
        return dp[ind1][ind2] = false;
    }
};