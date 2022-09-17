class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int minVal = prices[0], maxVal = prices[0];
        int len = prices.size();
        
        
        for (int i = 1; i < len; i++) {
            if (prices[i] < minVal) {
                prof += maxVal - minVal;
                
                minVal = maxVal = prices[i];
            }
            else {
                if (prices[i] > maxVal) {
                    maxVal = prices[i];
                }
                else {
                    prof += maxVal - minVal;
                    maxVal = minVal = prices[i];
                }
            }
        }
        
        prof += maxVal - minVal;
        
        return prof;
    }
};