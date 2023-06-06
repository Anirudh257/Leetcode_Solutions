// Time complexity: O(mn), Space complexity: O(n)
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        // vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
        vector<bool> curr(pLen + 1, false), prev(pLen + 1, false);

        //Base case 1: All characters matched
        prev[0] = true;

        // // Base case 2: Pattern is over but characters still remaining
        // for (int i = 1; i <= sLen; i++) {
        //     prev[0] = false; 
        // }

        // // Base case 3: String is over but pattern has some characters remaining
        // // Match only if pattern has all *s.
        for (int ind2 = 1; ind2 <= pLen; ind2++) {
            prev[ind2] = isAllStars(p, ind2);
        }

        for (int ind1 = 1; ind1 <= sLen; ind1++) {

            for (int ind2 = 1; ind2 <= pLen; ind2++) {
                curr[0] = isAllStars(p, ind2);

                if (s[ind1 - 1] == p[ind2 - 1] || p[ind2 - 1] == '?') {
                    curr[ind2] = prev[ind2 - 1];
                }
                else if (p[ind2 - 1] == '*') {

                    // match current character and extend * matching sequence.
                    // bool match = dp[ind1 - 1][ind2]; 
                    // bool noMatch = dp[ind1][ind2 - 1]; // Match 0 character;
                    curr[ind2] = prev[ind2] || curr[ind2 - 1];
                }
                else {
                    curr[ind2] = false;
                }
            }
            prev = curr;
        }
        
        return prev[pLen];
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