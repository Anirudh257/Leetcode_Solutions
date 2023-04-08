    class Solution {
public:
// Time complexity: O(4^n/3), Space complexity: O(4^n/3)
//Each 3 iterations a single digit becomes 4 digits. If we treat every three iterations as a recursion, 
// since we have n iterations, we then have n/3 such recursions. During each recursion a digit becomes fourfold,
// then after (n/3) recursions we have 4^(n/3) digits.


    string countAndSay(int n) {
        string res = "1";

        for (int i = 2; i <= n; i++) {
            string newRes;
            for (int j = 0, k = 0; j < res.size(); j = k) {
                while(k < res.size() && res[k] == res[j]) {
                    k++;
                }
                newRes += to_string(k - j) + res[j];
            }
            res = newRes;
        }

        return res;
    }
};