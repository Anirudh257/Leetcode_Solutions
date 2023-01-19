// Time complexity: O(n^2), Space complexity: O(n^2)
// DP approach, 
// s[l : r] is palindrome if s[l + 1:r - 1] is palindrome and s[l] == s[r]
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), maxPalLen = 1, maxPalSt = 0;

        bool dp[len][len];
        memset(dp, false, sizeof(dp));

        // Length 1 strings are always palindrome
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i+1][j - 1]) {
                        dp[i][j] = true;
                        if (maxPalLen < (j - i + 1)) {
                            maxPalLen = j - i + 1;
                            maxPalSt = i;
                        }

                    }
                }
            }
        }


        return s.substr(maxPalSt, maxPalLen);
    }
};
