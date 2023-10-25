// Time complexity: O(logn) as number of digits in a number = log n, Space complexity: O(1)
class Solution {
public:
    bool isHappy(int n) {
        
        // The numbers form an implicit cycle that could be solved via the 
        // Floyd Warshall algorithm.
        int slow = n;
        int fast = compSqDigSum(n);

        while(fast != 1 && slow != fast) {
            slow = compSqDigSum(slow);
            fast = compSqDigSum(compSqDigSum(fast));
        }

        return fast == 1;

    }
private:
    int compSqDigSum(int num) {
        int sqSum = 0;

        while(num) {
            int dig = num % 10;
            sqSum += dig*dig;
            num = num / 10;
        }

        return sqSum;
    }
};