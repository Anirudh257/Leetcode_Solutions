// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // The solution can be further optimized when we notice that 
        // we need to remove characters one by one traversing from left
        // This could be sped up by directly jumping 1 step ahead of the 
        // previous index location.
        int size = s.size();
        unordered_map<char, int> charMap;
        int l = 0, r = 0, maxLen = 0;

        while(r < size) {
            char ch = s[r];
            if (charMap.find(ch) != charMap.end()) {
                // Taking max to avoid recomputing previous substring.
                l = max(charMap[ch] + 1, l);
            }
            charMap[ch] = r;
            maxLen = max(maxLen,r - l + 1);
            r++;
        }

        return maxLen;
    }
};