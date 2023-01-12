// Time complexity: O(NlogN), Space complexity: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anags;

        map<vector<int>, vector<string>> anagMap;

        for (string s : strs) {
            vector<int> uniqRep = compRep(s);
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
    vector<int> compRep(string& s) {
        vector<int> chars(26);
        for (char ch : s) {
            int ind = ch - 'a';
            chars[ind]++;
        }
        return chars;
    }
};
