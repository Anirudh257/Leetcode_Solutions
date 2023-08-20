// Time complexity: O(mn), Space complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        matrix = transpose(matrix, m, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        matrix = revRows(matrix, m, n);

        return;
    }
private:
    vector<vector<int>> revRows(vector<vector<int>>& matrix, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0, k = n - 1; j < n/2; j++, k--) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
        }
        return matrix;
    }

    vector<vector<int>> transpose(vector<vector<int>>& matrix, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return matrix;
    }
};