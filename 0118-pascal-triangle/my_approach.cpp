// Time complexity: O(numRows^2), Space complexity: O(numRows^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri;

        if (numRows >= 1) {
            pasTri.push_back({1});
        }
        if (numRows >= 2) {
            pasTri.push_back({1, 1});
        }

        if (numRows <= 2) {
            return pasTri;
        }

        for (int i = 3; i <= numRows; i++) {
            vector<int> row(i, 1);
            vector<int> prevRow = pasTri.back();
            int rowSize = row.size();
            for (int j = 1; j < rowSize - 1; j++) {
                row[j] = prevRow[j - 1] + prevRow[j];
            }
            pasTri.push_back(row);
        }

        return pasTri;
    }
};