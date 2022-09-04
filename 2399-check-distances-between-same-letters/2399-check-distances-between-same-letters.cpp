class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int pos[26] = {};
        
        for (int i = 0; i < s.size(); i++) {
            int ind = s[i] - 'a';
            
            if (pos[ind] > 0 && distance[ind] != abs(i - pos[ind])) {
                return false;
            }
            pos[ind] = i + 1;
            
        }
        return true;
    }
};