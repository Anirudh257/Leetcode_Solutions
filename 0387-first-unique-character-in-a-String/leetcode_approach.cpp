// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counts;
        for (char ch : s) {
            counts[ch]++;
        }
        int size = s.length();
        for (int i = 0; i < size; i++) {
            char ch = s[i];
            if (counts[ch] == 1) {
                return i;
            }
        }

        return -1;
    }
};