class Solution {
public:
    // Time complexity: O(n*len(chars)), Space complexity: O(N) + Auxiliary Stack Space: O(N)
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string dec = "1";
        
        for (int i = 2; i <= n; i++) {
            dec = convStr(dec);
            // cout << i << " " << dec << endl;
        }
        // dec = convStr("21");
        
        return dec;
    }
private:
    string convStr(string str) {
        char prev = str[0];
        int size = str.size();
        int cnt = 1;
        string res = "";
        
        for (int i = 1; i < size; i++) {
            char curr = str[i];
            if (curr == prev) {
                cnt += 1;
            }
            else {
                // string num = string(1, curr);
                string num = "";
                num += prev;
                res += to_string(cnt) + num;
                cnt = 1;
            }
            prev = curr;
        }
        string num = string(1, prev);
        res += to_string(cnt) + num;
        return res;
    }
};