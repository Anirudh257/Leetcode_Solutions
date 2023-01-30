// Time complexity: O(26*26*N), Space complexity: O(26)
class Solution {
public:
    int largestVariance(string s) {
        int maxVar = 0, currVar = 0; // For ch1 +1, ch2 -1
        unordered_set<char> uniqCh(s.begin(), s.end());

        // Check if more than 1 character has occured in the substring
        bool hasCh2 = false, firstCh2 = false; 

        for (char ch1 : uniqCh) {
            for (char ch2 : uniqCh) {
                if (ch1 != ch2) {
                    currVar = 0, hasCh2 = false, firstCh2 = false;
                    for (auto ch : s) {
                        currVar += ch1 == ch;
                        if (ch == ch2) {
                            hasCh2 = true;
                            if (firstCh2 && currVar >= 0) {
                                firstCh2 = false;
                            }
                            // Reinitialize var to 0
                            else if (--currVar < 0) {
                                firstCh2 = true;
                                currVar = -1;
                            }
                        }
                        maxVar = max(maxVar, hasCh2 ? currVar : 0);
                    }
                }
            }
        }

        return maxVar;
    }
};
