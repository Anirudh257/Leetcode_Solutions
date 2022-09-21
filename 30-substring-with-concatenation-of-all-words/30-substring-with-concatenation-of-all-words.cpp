class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        
        // Time complexity: O(a + n*b), a = numWords, b = wordSz, Space complexity: O(a + b)
        int numWords = words.size();
        int wordSz = words[0].size();
        int sLen = s.length();
        
        if (sLen < numWords*wordSz) {
            return {};
        }
        
        
        for (string word : words) {
            counts[word]++;
        }
        
        vector<int> inds;
        
        for (int i = 0; i < sLen - numWords*wordSz + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < numWords; j++) {
                string word = s.substr(i + j*wordSz, wordSz);
                
                if (counts.count(word)) {
                    seen[word]++;
                    
                    if (seen[word] > counts[word]) {
                        break;
                    }
                    
                }
                else {
                    break;
                }
            }
            if (j == numWords) {
                inds.push_back(i);
            }
        }
        
        
        return inds;
    }
};