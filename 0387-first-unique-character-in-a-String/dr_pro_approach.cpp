// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> countsIdxMap;
        int size = s.size();
        int idx = size;
        for (int i = 0; i < size; i++) {
            char ch = s[i];
            countsIdxMap[ch].first++;
            countsIdxMap[ch].second = i;
        }

        for (const auto & [c, p] : countsIdxMap) {
            if (p.first == 1) {
                idx = min(idx, p.second);
            } 
        }
        return idx == size ? -1 : idx;
    }
};