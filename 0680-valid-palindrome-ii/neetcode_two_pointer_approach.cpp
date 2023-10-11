// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        int size = s.size();
        int st = 0, end = size - 1;

        while(st < end) {
            if (s[st] != s[end]) {
                // check by deleting either s[st] or s[end] character
                return checkPal(s, st + 1, end) || checkPal(s, st, end - 1);
            }
            st++, end--;
        }
        return true;
    }
private:
    bool checkPal(string& s, int i, int j) {
        int st = i, end = j;
        while(st < end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};