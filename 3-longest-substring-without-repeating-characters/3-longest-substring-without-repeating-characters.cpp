class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time complexity: O(N), Space complexity: O(N)
        int l = 0, r = 0;
        int len = s.size();
        // unordered_map<char, int> chInd;
        vector<int> chInd(256, -1);
        int maxLen = 0;
        
        while(r < len) {
            char right = s[r];
            
            if (chInd[right] != -1) {
                if (l <= chInd[right]) {
                    l = chInd[right] + 1;
                }
            }
            chInd[right] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        
        return maxLen;
    }
};