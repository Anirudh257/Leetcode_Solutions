// Time complexity: O(nm), Space complexity: O(nm)
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));

        //Base case 1: All characters matched
        dp[0][0] = true;

        // Base case 2: Pattern is over but characters still remaining
        for (int i = 1; i <= sLen; i++) {
            dp[i][0] = false; 
        }

        // Base case 3: String is over but pattern has some characters remaining
        // Match only if pattern has all *s.
        for (int ind2 = 1; ind2 <= pLen; ind2++) {
            dp[0][ind2] = isAllStars(p, ind2);
        }

        for (int ind1 = 1; ind1 <= sLen; ind1++) {
            for (int ind2 = 1; ind2 <= pLen; ind2++) {
                if (s[ind1 - 1] == p[ind2 - 1] || p[ind2 - 1] == '?') {
                    dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
                }
                else if (p[ind2 - 1] == '*') {

                    // match current character and extend * matching sequence.
                    // bool match = dp[ind1 - 1][ind2]; 
                    // bool noMatch = dp[ind1][ind2 - 1]; // Match 0 character;
                    dp[ind1][ind2] = dp[ind1 - 1][ind2] || dp[ind1][ind2 - 1];
                }
                else {
                    dp[ind1][ind2] = false;
                }
            }
        }
        
        return dp[sLen][pLen];
    }
private:
    bool isAllStars(string& p, int ind) {
        for (int i = 0; i < ind; i++) {
            char ch = p[i];
            if (ch != '*') {
                return false;
            }
        }
        return true;
    }

};