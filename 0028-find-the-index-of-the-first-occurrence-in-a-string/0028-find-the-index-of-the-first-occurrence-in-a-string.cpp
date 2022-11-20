class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        int firInd = INT_MAX;
        int l1 = 0, l2 = 0;
        
        for (; l1 < m; l1++) {
            int prevL1 = l1;
            l2 = 0;
            while (needle[l2] == haystack[prevL1] && l2 < n && prevL1 < m) {
                l2++;
                prevL1++;
            }
            // cout << l2 << endl;
            if (l2 == n) {
                firInd = min(firInd, l1);
            }
            // l1 = prevL1;
        }
        
        return firInd == INT_MAX ? -1 : firInd;
    }
};