// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string res="";
        string temp ="";
        for (auto &ch : s) {
            if (ch == ' ') {
                if (temp.size() != 0) {
                    stk.push(temp);
                    temp = "";
                }
            }
            else {
                temp += ch;
            }
        }

        if (temp.size() != 0) {
            stk.push(temp);
        }

        while(stk.size() != 1) {
            string top = stk.top();
            res += top + " ";
            stk.pop();
        }

        res += stk.top();
        stk.pop();

        return res;
    }
};