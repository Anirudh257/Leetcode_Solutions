// Time complexity: O(mn), Space complexity: O(mn) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int ind1 = 0; ind1 <= len1; ind1++) {
            dp[ind1][0] = ind1;
        }

        for (int ind2 = 0; ind2 <= len2; ind2++) {
            dp[0][ind2] = ind2;
        }
        
        for (int ind1 = 1; ind1 <= len1; ind1++) {
            for (int ind2 = 1; ind2 <= len2; ind2++) {
                int del = 1e9, ins = 1e9, repl = 1e9;
                if (word1[ind1 - 1] == word2[ind2 - 1]) {
                    dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
                }
                else {
                    del = dp[ind1 - 1][ind2];
                    ins = dp[ind1][ind2 - 1];
                    repl = dp[ind1 - 1][ind2 - 1];
                    dp[ind1][ind2] = 1 + min({del, ins, repl});

                }
            }
        }

        return dp[len1][len2];
    }
};