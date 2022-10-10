class Solution {
public:
     int minCharacters(string a, string b) {
           int aLen = a.length(), bLen = b.length(), res = aLen + bLen;
           vector<int> freqA(26), freqB(26);

           for (char ch : a) {
                freqA[ch - 'a']++;
           }

           for (char ch : b) {
                freqB[ch - 'a']++;
           }

           for (int i = 0; i < 26; i++) {
                res = min(res, aLen + bLen - freqA[i] - freqB[i]);
               
               if (i > 0) {
                     freqA[i] += freqA[i - 1];
                     freqB[i] += freqB[i - 1];
              }
             if (i < 25) {
                   res = min(res, aLen - freqA[i] + freqB[i]);
                   res = min(res, bLen - freqB[i] + freqA[i]);
             }

           }

           return res;
     }
};
