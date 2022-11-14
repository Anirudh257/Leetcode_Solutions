class Solution {
public:
    // Time complexity: O(N*4^N), Space complexity: O(4^N)
    vector<string> letterCombinations(string digits) {
        int size = digits.size();
        if (size == 0) {
            return {};
        }
        vector<string> combs;
        
        vector<string> telCom = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        deque<string> dq;
        dq.push_back("");
        
        for (char dig : digits) {
            int num = dig - '0';
            
            for (int i = dq.size() - 1; i >= 0; i--) {
                string tok = dq.front();
                dq.pop_front();
                
                for (char ch : telCom[num]) {
                    dq.push_back(tok + ch);
                }
            }            
        }
        
        return vector<string>(dq.begin(), dq.end());
    }
};
