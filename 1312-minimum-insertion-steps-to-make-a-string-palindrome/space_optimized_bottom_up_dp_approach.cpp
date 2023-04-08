// Time complexity: O(n^2), Space complexity: O(n) 
class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<int> next(len, 0), curr(len, 0);

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                int numInsert = 0;
                if (s[i] == s[j]) {
                    numInsert = next[j - 1];
                }
                else {
                    numInsert = 1   + min(next[j], curr[j - 1]);
                }
                curr[j] = numInsert;
            }
            next = curr;
        }

        return curr[len - 1];
    }
};