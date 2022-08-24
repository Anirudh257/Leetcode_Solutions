class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time complexity: O(n), Space complexity: O(256)
        
        int len = s.length();
        int subLen = -1e8;
        
        int l = 0, r = 0;
        
        vector<int> counts(256, -1);
        
        
        while(r < len) {
            char ch = s[r];
            
            // if (counts.find(ch) != counts)
            int ind = counts[ch];
            
            if (ind != -1 && ind >= l && ind < r) {
                l = ind + 1;
            }
            
            // while(counts[ch] > 1) {
            //     char ch = s[l];
            //     l++;
            //     counts[ch]--;
            // } 
            
            subLen = max(subLen, r - l + 1);
            
            counts[ch] = r;
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