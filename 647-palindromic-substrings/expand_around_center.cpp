// Time complexity: O(N^2), Space complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int numSubs = 0;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            numSubs += expandAroundCentre(s, i, i);

            numSubs += expandAroundCentre(s, i, i + 1);
        }

        return numSubs;
    }
private:
    int expandAroundCentre(string& s, int lo, int hi) {
        int numSubs = 0;

        while(lo >= 0 && hi < s.size()) {
            if (s[lo] != s[hi]) {
                break;
            }
            lo--;
            hi++;
            numSubs++;
        }
        
        return numSubs;
    }
    
};
