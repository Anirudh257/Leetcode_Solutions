// Time complexity: O(nm), Space complexity: O(n) 
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<double> prev(len2 + 1, 0);
        
        prev[0] = 1;

        for (int i = 1; i <= len1; i++) {
            for (int j = len2; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] += prev[j - 1];
                }
            }
        }

        return (int)prev[len2];
    }
};