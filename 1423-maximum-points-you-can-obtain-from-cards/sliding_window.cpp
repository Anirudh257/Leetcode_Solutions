class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Time complexity: O(n), Space complexity: O(1)
        int len = cardPoints.size();
        
        int subSc = 0;
        
        for (int i = 0; i < k; i++) {
            subSc += cardPoints[i];
        }
        
        int maxSc;
        maxSc = subSc;
        
        for (int i = k - 1, j = len - 1; ~i; i--, j--) {
            subSc += cardPoints[j] - cardPoints[i];
            maxSc = max(maxSc, subSc);
        }
        
        return maxSc;
    }
};
