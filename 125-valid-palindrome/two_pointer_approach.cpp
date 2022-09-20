class Solution {
public:
    bool isPalindrome(string s) {
        // Time complexity: O(n), Space complexity: O(1)
        int len = s.size();
        
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            while(i < j && !isalnum(s[i])) {
                i++;
            }
            while(i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }
        return true;
    }
};
