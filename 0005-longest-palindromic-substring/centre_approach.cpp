// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxPalLen = 0, stPal = 0, curPalLen = 0;
        
        for (int i = 0; i < len; i++) {
            for (int centLen = 0; centLen <= 1; centLen++) {
                int l = i, r = i + centLen;
                
                while(l >= 0 && r < len && s[l] == s[r]) {
                    l--;
                    r++;
                }
                
                l++;
                r--;
                curPalLen = r - l + 1;
                if (curPalLen > maxPalLen) {
                    stPal = l;
                    maxPalLen = curPalLen;
                }
            }
        }
        
        string sub = s.substr(stPal, maxPalLen);
        return sub;
    }
};