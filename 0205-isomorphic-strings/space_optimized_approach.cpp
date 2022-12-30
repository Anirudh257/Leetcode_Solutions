// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char sMap[128] = {0};
        char tMap[128] = {0};
        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (sMap[s[i]] != tMap[t[i]]) {
                return false;
            }
            sMap[s[i]] = i + 1;
            tMap[t[i]] = i + 1;
        }

        return true;
    }
};
