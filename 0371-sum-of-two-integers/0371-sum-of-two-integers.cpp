class Solution {
public:
    // Time complexity: O(1)
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        
        double powSum = pow(10, a)*pow(10, b);
        double sum = log10(powSum);
        
        return (int)sum;   
    }
};