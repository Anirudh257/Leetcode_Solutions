// Time complexity: O(n log k), Space complexity: O(k) for heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int numRows = matrix.size(), numCols = matrix[0].size();
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
                
            }
        }
        return pq.top();
    }
};