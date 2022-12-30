// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> chStrMap;
        unordered_map<string, char> strChMap;

        vector<string> words = remSpace(s);
        int len = pattern.size();

        if (len != words.size()) {
            return false;
        }

        for (int i = 0; i < len; i++) {
            char ch = pattern[i];
            string word = words[i];
            if (chStrMap.find(ch) == chStrMap.end()) {
                chStrMap[ch] = word;
            }
            else {
                string match = chStrMap[ch];
                if (match != word) {
                    return false;
                }
            }
            if (strChMap.find(word) == strChMap.end()) {
                strChMap[word] = ch;
            }
            else {
                char mat = strChMap[word];
                if (mat != ch) {
                    return false;
                }
            }
        }

        return true;
    }
private:
    vector<string> remSpace(string s) {
        vector<string> words;
        int len = s.length();
        string word = "";

        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (ch != ' ') {
                word += ch;
            }
            else {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);
        return words;
    }
};
