class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hMap(128, 0); // signifying lowercase + uppercase character locations
        int sLen = s.length(), reqLen = t.size();
        
        for (char ch : t) {
            hMap[ch]++;
        }
        
        
        int minSt = -1, minLen = INT_MAX, st = 0;
        int r = 0, l = 0;
        
        while(r < sLen) {
            char ch = s[r++];
            // hMap[ch];
            
            if (--hMap[ch] >= 0) {
                reqLen--;
            }
            // r++;
            while(reqLen == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    minSt = l;
                }
                
                char ch = s[l++];
                hMap[ch]++;
                if (hMap[ch] > 0) {
                    // hMap[ch]++;
                    reqLen++;
                    // l++;
                }
            }
            // r++;
        }
        
        
        return minLen != INT_MAX ? s.substr(minSt, minLen) : "";
    }
};