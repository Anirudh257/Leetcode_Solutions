// Time complexity: O(2N), Space complexity: O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute force computing all substrings and  checking the length of 
        // longest substring without repeating characters takes O(n^2) steps.
        // We are repeating the check of many substrings in this case.
        // If we know that substring s[ij] has already been checkedn, we only need to check s[j+1n]
        int size = s.size();
        unordered_map<char, int> subMap;
        int l = 0, r = 0, maxLen = 0;

        while(r < size) {
            char ch = s[r];
            subMap[ch]++;
            while(subMap[ch] > 1) {
                char ch = s[l];
                subMap[ch]--;
                l++;
            }
            maxLen = max(maxLen,r - l + 1);
            r++;
        }

        return maxLen;
    }
};