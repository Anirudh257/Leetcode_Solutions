// Time complexity: O(n), Space complexity: O(n), n = #words/len(s)
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        string temp="";
        for (char ch: s) {
            if (ch != ' ') {
                temp += ch;
            } 
            else {
                if (temp.size() != 0) {
                    words.push_back(temp);
                }
                temp = "";
            }
        }

        if (temp.size() != 0) {
            words.push_back(temp);
        }

        string res = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i != 0) {
                res += " ";
            }
        }

        return res;
    }
};