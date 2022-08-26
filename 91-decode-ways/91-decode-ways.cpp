class Solution {
public:
    int numDecodings(string s) {
        return compRec(s, 0);
    }
private:
    unordered_map<int, int> memo;
    
    int compRec(string s, int ind) {
        if (memo.find(ind) != memo.end()) {
            return memo[ind];
        }
        
        if (ind == s.length()) {
            return 1;
        }
        
        if (s[ind] == '0') {
            return 0;
        }
        
        if (ind == s.length() - 1) {
            return 1;
        }
        
        int numWays = compRec(s, ind + 1);
        
        if (stoi(s.substr(ind, 2)) <= 26) {
            numWays += compRec(s, ind + 2);
        }
        
        return memo[ind] = numWays;
        
    }
    
};