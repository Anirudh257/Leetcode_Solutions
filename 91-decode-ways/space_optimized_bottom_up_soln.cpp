// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        int len = s.length();

        int oneBack = 1;
        int twoBack = 1;

        for (int i = 1; i < len; i++) {
            int curr = 0;
            if (s[i] != '0') {
                curr = oneBack;
            }

            int twoDig = stoi(s.substr(i - 1, 2));

            if (twoDig >= 10 && twoDig <= 26) {
                curr += twoBack;
            }
            twoBack = oneBack;
            oneBack = curr;
        }

        return oneBack;
    }
};
