static const unordered_map<int, vector<char>> kT9Mapping {{2, {'a', 'b', 'c'}},
                                         {3, {'d', 'e', 'f'}},
                                         {4, {'g', 'h', 'i'}},
                                         {5, {'j', 'k', 'l'}},
                                         {6, {'m', 'n', 'o'}},
                                         {7, {'p', 'q', 'r', 's'}},
                                         {8, {'t', 'u', 'v'}},
                                         {9, {'w', 'x', 'y', 'z'}}};

// Time complexity: O(n*4^n), Space complexity: O(4^n)
// Max number of characters per integer can be 4 and max length of path can be 4^n
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        
        vector<string> combs;
        
        int size = digits.size();
        
        compCombs(combs, "", 0, digits);
                
        
        return combs;
    }
private:
    
    void compCombs(vector<string>& combs, string word, int ind, string& digits) {
        if (word.size() == digits.size()) {
            combs.push_back(word);
            return;
        }
        char curr = digits[ind];
        int num = curr - '0';
        
        for (char ch: kT9Mapping.at(num)) {
            compCombs(combs, word + ch, ind + 1, digits);
        }
        
        
        return;
    }

};