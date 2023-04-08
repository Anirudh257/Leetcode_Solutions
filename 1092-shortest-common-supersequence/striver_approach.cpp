// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        
        string shortCommSeq = compLCS(str1, str2, len1, len2);

        return shortCommSeq;
    }
private:
    string compLCS(string& str1, string& str2, int len1, int len2) {
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        int lcsLen = 0;

        string scseq;

        for (int ind1 = 1; ind1 <= len1; ind1++) {
            for (int ind2 = 1; ind2 <= len2; ind2++) {
                if (str1[ind1 - 1] == str2[ind2 - 1]) {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else {
                    dp[ind1][ind2] = max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
                }
                lcsLen = max(lcsLen, dp[ind1][ind2]);
            }
        }

        int i = len1, j = len2;

        while(i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scseq += str1[i - 1];
                i--, j--;                
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                scseq += str1[i - 1];
                i--;
            }
            else {
                scseq += str2[j - 1];
                j--;
            }
        }

        while(i > 0) {
            scseq += str1[i - 1];
            i--;
        }

        while(j > 0) {
            scseq += str2[j - 1];
            j--;
        }

        reverse(scseq.begin(), scseq.end());

        return scseq;
    }
};