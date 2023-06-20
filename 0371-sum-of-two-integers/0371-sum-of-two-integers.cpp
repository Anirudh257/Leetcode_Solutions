// Time complexity: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int ans = a ^ b;
            int carry = unsigned(a & b) << 1;
            a = ans;
            b = carry;
        }
        return a;
    }
};