class Solution {
public:
    // Time complexity: O(n*2^2n) 2n total subsets possible out of which only valid subsequences taken
    // Space complexity: O(n*2^2n)
    vector<string> generateParenthesis(int n) {
        vector<string> pars;
        
        genPar(n, "(", 1, 0, pars);
        
        return pars;
    }
private:
    void genPar(int n, string par, int numOpen, int numClose, vector<string>& pars) {
        if (numOpen == n && numClose == n) {
            pars.push_back(par);
            return;
        }
        
        if (numOpen < n) {
            genPar(n, par + '(', numOpen + 1, numClose, pars);
        }
        
        if (numClose < n && numClose < numOpen) {
            genPar(n, par + ')', numOpen, numClose + 1, pars);
        }
        
        
        return;
    }
};