// Time complexity: O(N*N), Space complexity: O(N), N = length(string)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        return compLCS(s, t);
    }
private:
    int compLCS(string& s, string& t) {
        int len = s.length();
        vector<int> cur(len + 1, 0);
        vector<int> prev(len + 1, 0);

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                }
                else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        return prev[len];

    }
};
