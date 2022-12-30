// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> ch2I;
        unordered_map<string, int> s2I;
        int len = pattern.size(), i = 0;
        istringstream in(s);

        for (string word; in >> word; i++) {
            if (i == len || s2I[word] != ch2I[pattern[i]]) {
                return false;
            }
            else {
                s2I[word] = ch2I[pattern[i]] = i + 1;
            }
        }
        return i == len;
    }
};
