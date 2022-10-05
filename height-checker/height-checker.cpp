class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        
        int nonMatch = 0, size = heights.size();
        
        for (int i = 0; i < size; i++) {
            if (heights[i] != expected[i]) {
                nonMatch++;
            }
        }
        return nonMatch;
    }
};