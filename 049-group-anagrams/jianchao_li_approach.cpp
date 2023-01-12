// Time complexity: O(MN), Space complexity: O(M), M = number of strings, N = average length of a string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anags;

        unordered_map<string, vector<string>> anagMap;

        for (string s : strs) {
            string uniqRep = compRep(s);
            anagMap[uniqRep].push_back(s);
        }

        for (auto &x : anagMap) {
            vector<string> temp;
            for (auto &y : x.second) {
                temp.push_back(y);
            }
            anags.push_back(temp);
        }

        return anags;
    }
private:
    string compRep(string& s) {
        vector<int> chars(26);
        int count[26] = {0};
        
        for (char c : s) {
            count[c - 'a']++;
        }

        string str;

        for (int c = 0; c < 26; c++) {
            str += string(count[c], c + 'a');
        }
        return str;

    }
};
