class Solution {
public:
    string minWindow(string s, string t) {
        // Time complexity: O(|s| + |t|), Space complexity: O(1)
        
        vector<int> hMap(128, 0); // signifying lowercase + uppercase character locations
        
        int sLen = s.length(), reqLen = t.size();
        
        for (char ch : t) {
            hMap[ch]++;
        }
        
        
        int minSt = -1, minLen = INT_MAX, st = 0;
        int r = 0, l = 0;
        
        while(r < sLen) {
            // Expand window as it is applicable
            char ch = s[r++];
            
            if (--hMap[ch] >= 0) {
                reqLen--;
            }
            while(reqLen == 0) {
                // Contract window till it is applicable
                if (r - l < minLen) {
                    minLen = r - l;
                    minSt = l;
                }
                
                char ch = s[l++];
                hMap[ch]++;
                if (hMap[ch] > 0) {
                    reqLen++;
                }
            }
        }
                
        return minLen != INT_MAX ? s.substr(minSt, minLen) : "";
    }
};