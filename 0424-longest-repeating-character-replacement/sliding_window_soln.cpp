// Time complexity: O(N), Space complexity: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxLen = 0, maxFreq = 0;
        int l = 0, size = s.size();

        for (int r = 0; r < size; r++) {
            char ch = s[r];
            freq[ch]++;
            
            maxFreq = max(maxFreq, freq[ch]);

            while ((r - l + 1 - maxFreq) > k) {
                freq[s[l]]--;
                l += 1;
            }
            maxLen = max(maxLen, (r - l + 1));

        }


        return maxLen;
    }
};
