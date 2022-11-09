class Solution {
public:
    // Time complexity: O(26*26*n), n = len(s), Space complexity: O(26)
    int largestVariance(string s) {
        int maxVar = 0, var = 0;
        
        int len = s.size();
        
        unordered_set<char> uniq(s.begin(), s.end());
        
        for (char fir : uniq) {
            for (char sec : uniq) {
                bool secOcc = false, secFirst = false;
                int var = 0;
                
                for (auto ch : s) {
                    var += ch == fir;
                    
                    if (ch == sec) {
                        secOcc = true;
                        
                        if (secFirst && var >= 0) {
                            secFirst = false;
                        }
                        else if (--var < 0) {
                            var = -1;
                            secFirst = true;
                        }
                        
                    }
                    maxVar = max(maxVar, secOcc ? var : 0);
                }
            }
        }
        return maxVar;
    }
};