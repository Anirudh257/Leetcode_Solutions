// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxPalLen = 1;
        int maxSt = 0;
        bool flag = false;

        for (int i = 0; i < len; i++) {
            int l = i - 1;
            int r = i + 1;
            while(l >= 0 && r < len && s[l] == s[r]) {
                if (maxPalLen < (r - l + 1)) {
                    maxPalLen = r - l + 1;
                    maxSt = l;
                }
                l--;
                r++;
            }
            int fir = i;
            int sec = i + 1;
            int st = fir - 1;
            int st2 = sec + 1;
            if (s[fir] == s[sec]) {
                if (maxPalLen < (sec - fir + 1)) {
                    maxPalLen = sec - fir + 1;
                    maxSt = fir;
                }
                while(st >= 0 && st2 < len && s[st] == s[st2]) {
                    if (maxPalLen < (st2 - st + 1)) {
                        maxPalLen = st2 - st + 1;
                        maxSt = st;
                    }
                    st--;
                    st2++;
                }
            }



        }

        cout << maxPalLen << " " << maxSt << endl;

        // return "";

        return s.substr(maxSt, maxPalLen);
    }
};
