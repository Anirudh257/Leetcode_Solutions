// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap;
        unordered_map<char, char> revMap;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            char ch1 = s[i];
            char ch2 = t[i];
            if (umap.find(ch1) == umap.end()) {
                umap[ch1] = ch2;
            }
            else {
                char pre = umap[ch1];
                if (pre != ch2) {
                    return false;
                }
            }
            if (revMap.find(ch2) == revMap.end()) {
                revMap[ch2] = ch1;
            }
            else {
                char rev = revMap[ch2];
                if (ch1 != rev) {
                    return false;
                }
            }
        }
        

        return true;
    }
};
