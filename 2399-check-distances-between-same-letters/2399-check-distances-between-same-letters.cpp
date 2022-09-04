class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        // Time complexity: O(n), Space complexity: O(n)
        
        unordered_map<char, int> chInd;
        
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (chInd.find(ch) != chInd.end()) {
                int dist = abs(chInd[ch] - i) - 1;
                int chInd = ch - 'a';
                if (dist != distance[chInd]) {
                    return false;
                }
            }
            chInd[ch] = i;
        }
        
        return true;
    }
};