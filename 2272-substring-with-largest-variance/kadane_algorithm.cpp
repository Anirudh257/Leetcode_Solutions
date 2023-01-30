// Time complexity: O(26*26*N), Space complexity: O(1), N = length of string
class Solution {
public:
    int largestVariance(string s) {
        int freq[26];
        int maxVar = 0;

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Iterating for only the 26 characters. Consider only 2 characters at a time.
        // Keep incrementing the count of both and only if freq[ch2] > freq[ch1]
        // reinitialize the substring as we will never get a better answer in the future. 
        for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                
                if (ch1 == ch2 || !freq[ch1 - 'a'] || !freq[ch2 - 'a']) {
                    continue;
                }

                for (int rev = 1; rev <= 2; rev++) {
                    int cnt1 = 0, cnt2 = 0;

                    for (auto &c : s) {
                        cnt1 += c == ch1;
                        cnt2 += c == ch2;

                        if (cnt1 < cnt2) {
                            cnt1 = 0, cnt2 = 0;
                        }
                        else if (cnt1 > 0 && cnt2 > 0) {
                            maxVar = max(maxVar, cnt1 - cnt2);
                        }
                    }
                    // Reverse the string and recheck again for edge cases
                    reverse(s.begin(), s.end());
                }
                


            }
        }

        return maxVar;
    }
};
