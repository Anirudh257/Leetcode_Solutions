// Time complexity: O(mn), Space complexity: O(n) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();

        vector<int> prev(len2 + 1, 0), curr(len2 + 1, 0);

        for (int ind2 = 0; ind2 <= len2; ind2++) {
            prev[ind2] = ind2;
        }
        
        for (int ind1 = 1; ind1 <= len1; ind1++) {
            curr[0] = ind1; //Base case 
            for (int ind2 = 1; ind2 <= len2; ind2++) {
                int del = 1e9, ins = 1e9, repl = 1e9;
                if (word1[ind1 - 1] == word2[ind2 - 1]) {
                    curr[ind2] = prev[ind2 - 1];
                }
                else {
                    del = prev[ind2];
                    ins = curr[ind2 - 1];
                    repl = prev[ind2 - 1];
                    curr[ind2] = 1 + min({del, ins, repl});
                    }
            }
            prev = curr;
        }

        return prev[len2];
    }
};