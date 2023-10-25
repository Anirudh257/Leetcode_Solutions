// Time complexity: O(logn) as number of digits in a number = log n, Space complexity: O(log N)
class Solution {
public:
    bool isHappy(int n) {

        unordered_set<long long int> occurSums;
        occurSums.insert(n);
        long long int reqSum = n;
        
        while(reqSum != 1) {
            reqSum = compSqDigSum(reqSum);
            
            if (occurSums.count(reqSum)) {
                return false;
            }

            occurSums.insert(reqSum);
            
        }

        return true;
    }
private:
    long long int compSqDigSum(long long int num) {
        string strNum = to_string(num);
        long long int sqSum = 0;

        for (char ch: strNum) {
            int numInd = ch - '0';
            sqSum += numInd*numInd;
        }

        return sqSum;
    }
};