class Solution {
public:
    bool isPalindrome(string s) {
        // Time complexity: O(n), Space complexity: O(n)
        string filterStr, revStr;
        
        for (auto ch : s) {
            if (isalnum(ch)) {
                filterStr += tolower(ch);
            }
        }
        
        revStr.resize(filterStr.size());
        reverse_copy(filterStr.begin(), filterStr.end(), revStr.begin());
        
        return revStr == filterStr;
    }
};
