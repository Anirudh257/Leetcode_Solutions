class Solution {
public:
    // Time complexity: O(n*len(chars)), Space complexity: O(n) 
    string countAndSay(int n) {
        string res = "1";
        int i = 1;
        if (n == 1) {
            return res;
        }

        while(i < n) {
            cout << i << " " << res << endl;
            res = countSay(res);
            i++;   
        }


        return res;
    }
private:
    string countSay(string& s) {
        string ans = "";

        char fCh = s[0];
        int prevInd = 0;
        int len = s.length();

        for (int i = 1; i < len; i++) {
            char ch = s[i];
            if (ch != fCh) {
                int numOcc = i - prevInd;    
                prevInd = i;
                ans += to_string(numOcc) + fCh;
                fCh = ch;
            }
        }

        ans += to_string(len - prevInd) + fCh;

        return ans;
    }
};