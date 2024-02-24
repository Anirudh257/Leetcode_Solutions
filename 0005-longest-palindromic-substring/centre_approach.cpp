// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        // Expanding from centres as number of centres = O(n)
        // Checking start and end of each substring takes O(n^2)
        int size = s.length();
        int st = 0, end = 0;
        int palLen = 0;

        for (int i = 0; i < size; i++) {
            // j means the centre-length, 0 for odd and 1 for even-centre
            for (int j = 0; j <= 1; j++) {
                int l = i;
                int r = i + j;

                while(l >= 0 && r < size && s[l] == s[r]) {
                    l--;
                    r++;
                }
                l++;
                r--;

                if (r - l > end - st) {
                    st = l;
                    end = r;
                }
            }
        }
        return s.substr(st, end - st + 1);
    }
};