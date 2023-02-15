class Solution {
public:
    int uniquePaths(int m, int n) {
        // Total Path length can only be of length (m - 1)/(n - 1)
        // Total number of right = m - 1 or total number of down = n - 1
        // = m - 1 + n - 1 = m + n - 2
        // Time complexity: O(min(m, n)), Space complexity: O(1)
        int numer = m + n - 2;
        int denom;
        if (m < n) {
            denom = m - 1;
        }
        else {
            denom = n - 1;
        }
        double numWays = 1;

        for (int i = 1; i <= denom; i++) {
            numWays = numWays *(numer - denom + i)/i;
        }


        return (int)numWays;
    }
};