// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int maxPalLen = 0, maxSt = 0, len = s.length();

        for (int i = 0; i < len; i++) {
            // Considering odd-length palindromes with s[i] as centre and expanding 
            // inwards and outwards
            int l = i, r = i;
            while(l >= 0 && r < len && s[l] == s[r]) {
                if (maxPalLen < (r - l + 1)) {
                    maxPalLen = r - l + 1;
                    maxSt = l;
                }
                l--;
                r++;
            }
            // Considering even-length palindromes with s[i]  and s[i + 1] as centre and   
            // expanding inwards and outwards
            l = i, r = i + 1;
            while(l >= 0 && r < len && s[l] == s[r]) {
                if (maxPalLen < (r - l + 1)) {
                    maxPalLen = r - l + 1;
                    maxSt = l;
                }
                l--;
                r++;
            }

        }
        
        return s.substr(maxSt, maxPalLen);
    }
};
