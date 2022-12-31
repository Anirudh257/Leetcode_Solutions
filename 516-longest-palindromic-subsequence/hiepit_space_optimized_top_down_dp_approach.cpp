// Time complexity: O(N^2), Space complexity: O(N) 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<int> cur(len, 0), prev(len, 0);

        for (int i = len - 1; i >= 0; i--) {
            cur[i] = 1;
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    cur[j] = 2 + prev[j - 1];
                }
                else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        return prev[len - 1];
    }
};
