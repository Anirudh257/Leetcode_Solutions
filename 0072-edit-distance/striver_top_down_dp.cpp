// Time complexity: O(mn), Space complexity: O(mn) + Auxiliary stack space: O(m + n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return editDist(word1, word2, len1 - 1,len2 - 1, dp);
    }
private:
    int editDist(string& word1, string& word2, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind2 < 0 || ind1 <  0) {
            return max(ind1, ind2) + 1;
        }

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        int del = INT_MAX, ins = INT_MAX, repl = INT_MAX;
        if (word1[ind1] == word2[ind2]) {
            return dp[ind1][ind2] = editDist(word1, word2, ind1 - 1, ind2 - 1, dp);
        }
        else {
            del = editDist(word1, word2, ind1 - 1, ind2, dp) + 1;
            ins = editDist(word1, word2, ind1, ind2 - 1, dp) + 1;
            repl = editDist(word1, word2, ind1 - 1, ind2 - 1, dp) + 1;
        }
        return dp[ind1][ind2] = min({del, ins, repl});
    }
};