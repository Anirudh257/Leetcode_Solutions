class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int subLen = -1e8;
        
        int l = 0, r = 0;
        
        vector<int> counts(256, 0);
        
        
        while(r < len) {
            char ch = s[r];
            
            counts[ch]++;
            
            while(counts[ch] > 1) {
                char ch = s[l];
                l++;
                counts[ch]--;
            } 
            
            subLen = max(subLen, r - l + 1);
            r++;
        }
        
        //abcabcbb
        
        // ch a
        
        // r 0
        
        // l 0
        
        // subLen = 1
        
        /*
            counts
                a  1   
        */
        
        return (subLen != -1e8) ? subLen : 0;
    }
};