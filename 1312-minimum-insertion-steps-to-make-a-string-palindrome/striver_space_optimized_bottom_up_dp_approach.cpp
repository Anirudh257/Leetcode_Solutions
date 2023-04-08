// Preserve palindromic part and just repeat the non-palindromic part.
// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();

        return len - lps(s);
    }
private:
    int lps(string& s) {
        int len = s.length();
        string t = s;
        reverse(t.begin(), t.end());

        return lcs(s, t);
    }

    int lcs(string& s, string& t) {
        int sLen = s.length(), tLen = t.length();
        // vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1, 0));
        vector<int> prev(tLen + 1), curr(tLen + 1);

        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= tLen; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[tLen];
    }
};