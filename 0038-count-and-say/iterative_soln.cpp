class Solution {
public:
    // Time complexity: O(n*m), m = length of decoded string, Space complexity: O(m)
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        string res = "11";
        
        for (int i = 3; i <= n; i++) {
            string temp = "";
            int cnt = 1;
            res += '&';
            
            for (int j = 1; j < res.size(); j++) {
                if (res[j] != res[j - 1]) {
                    temp += to_string(cnt);
                    temp += res[j - 1];
                    cnt = 1;
                }
                else {
                    cnt++;
                }
            }
            res = temp;
        }
        
        
        return res;
    }
};
