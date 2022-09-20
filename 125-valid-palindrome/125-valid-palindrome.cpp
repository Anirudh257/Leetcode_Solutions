class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        // char ch = 'Z';
        // char newCh = toLow(ch);
        // cout << newCh << endl;
        
        for (char ch : s) {
            if (isalpha(ch)) {
                // ch = to_lower(ch);
                if (ch >= 'A' && ch <= 'Z') {
                    // int val = ch;
                    // val += 32;
                    // ch = val;
                    ch = ch + (int)32;
                }
                newS += ch;
            }
            else if (ch >= '0' && ch <= '9') {
                newS += ch;
                
            }
        }
        
        
        
        // cout << newS << endl;
        
        return isPal(newS);
    }
private:
    bool isPal(string s) {
        int len = s.size();
        for (int i = 0, j = len - 1; i < len/2; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};