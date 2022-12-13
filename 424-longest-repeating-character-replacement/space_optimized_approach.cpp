// Time complexity: O(N), Space complexity: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxLen = 0, maxFreq = 0;
        int l = 0, size = s.size();

        for (int r = 0; r < size; r++) {
            char ch = s[r];
            int ind = ch - 'A';
            freq[ind]++;
            
            maxFreq = max(maxFreq, freq[ind]);

            while ((r - l + 1 - maxFreq) > k) {
                freq[s[l] - 'A']--;
                l += 1;
            }
            maxLen = max(maxLen, (r - l + 1));

        }


        return maxLen;
    }
};
