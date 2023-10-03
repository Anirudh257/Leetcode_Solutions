// Time complexity: O(r^2), Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri;
        
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp = genRow(i);
            pasTri.push_back(temp);
        }

        return pasTri;
    }
private:
    vector<int> genRow(int r) {
        vector<int> tempRow = {1};
        int ans = 1;
        for (int c = 1; c < r; c++) {
            ans = ans*(r - c);
            ans /= c;
            tempRow.push_back(ans);
        }

        return tempRow;
    }
};