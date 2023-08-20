// Time complexity: O(log(m + n)), Space complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int endInd = searchCols(matrix, m, n, target);

        if (matrix[endInd][n - 1] == target) {
            return true;
        }

        return binSearch(matrix[endInd], target, 0, n - 1);

    }
private:
    int binSearch(vector<int>& rowMat, int target, int st, int end) {
        int mid = st + (end - st)/2;

        while(st <= end) {
            mid = st + (end - st)/2;
            if (rowMat[mid] == target) {
                return true;
            }
            else if (rowMat[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }   
        return false;
    }

    int searchCols(vector<vector<int>>& matrix, int m, int n, int target) {
        int st = 0, end = m - 1;
        int mid = -1;

        while(st < end) {
            mid = st + (end - st)/2;
            if (matrix[mid][n - 1] == target) {
                return mid;
            }
            else if (matrix[mid][n - 1] < target) {
                st = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return end;
    }
};