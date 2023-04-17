// Time complexity: O(nm), Space complexity: O(n) 
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<double> curr(len2 + 1, 0), prev(len2 + 1, 0);

        curr[0] = prev[0] = 1;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int)curr[len2];
    }
};