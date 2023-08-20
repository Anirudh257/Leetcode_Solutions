// Time complexity: O(log(m*n)), Space complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int st = 0, end = m*n - 1;
        int pivInd, pivElem;
        while(st <= end) {
            pivInd = (st + end)/2;
            pivElem = matrix[pivInd/n][pivInd%n];
            if (pivElem == target) {
                return true;
            }
            else if (pivElem > target) {
                end = pivInd - 1;
            }
            else {
                st = pivInd + 1;
            }
        }

        return false;    
    }
};