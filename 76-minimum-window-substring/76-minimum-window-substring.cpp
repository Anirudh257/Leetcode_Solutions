class Solution {
public:
    string minWindow(string s, string t) {
        int tLen = t.length(), sLen = s.length();
        
        if (tLen > sLen) {
            return "";
        }
        int l = 0, r = 0, minSubLen = INT_MAX;
        int reqL = 0, reqR = 0;
        
        unordered_map<char, int> needMap;
        
        for (char ch : t) {
            needMap[ch]++;
        }
        
        int need = needMap.size();
        int have = 0;
        unordered_map<char, int> haveMap;
        
        while(r < sLen) {
            char ch = s[r];
            
            if (needMap.find(ch) != needMap.end()) {
                haveMap[ch]++;
                
                if (haveMap[ch] == needMap[ch]) {
                    have++;
                }
                
                while (have == need) {
                    char ch = s[l];
                    
                    if (haveMap.find(ch) != haveMap.end()) {
                        haveMap[ch]--;
                        
                        if (haveMap[ch] < needMap[ch]) {
                            have--;
                        }
                    }
                    if (minSubLen > r - l + 1) {
                        reqL = l;
                        reqR = r;
                        minSubLen = r - l + 1;
                    }
                    l++;
                }
            }
            r++;
        }
        // cout << l << "  " << r << endl;
        return minSubLen == INT_MAX ? "" : s.substr(reqL, reqR - reqL + 1);   
    }
};