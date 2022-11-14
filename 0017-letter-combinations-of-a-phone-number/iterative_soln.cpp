class Solution {
public:
    const vector<string> tele = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // Time complexity: O(n*4^n), Space complexity: O(4^n)
    
    vector<string> letterCombinations(string digits) {
        
        if (digits == "") {
            return {};
        }
        
        vector<string> combs = {""};
        
        for (auto dig : digits) {
            vector<string> tmp;
            int num = dig - '0';
            for (auto ch : tele[num]) {
                for (string s : combs) {
                    tmp.push_back(s + ch);
                }
            }
            swap(tmp, combs);
        }
        
        return combs;
    }
};
