class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int maxSc = 0;
        vector<int> frontSc(k + 1, 0);
        vector<int> rearSc(k + 1, 0);
        
        for (int i = 0; i < k; i++) {
            frontSc[i + 1] = frontSc[i] + cardPoints[i];
            rearSc[i + 1] = cardPoints[len - i - 1] + rearSc[i];
        }
        
        for (int i = 0; i <= k; i++) {
            maxSc = max(frontSc[i] + rearSc[k - i], maxSc);
        }
        
        
        return maxSc;
    }
};