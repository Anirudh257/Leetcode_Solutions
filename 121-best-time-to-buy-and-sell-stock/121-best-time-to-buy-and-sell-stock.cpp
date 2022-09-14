class Solution {
public:
    // Time complexity: O(N), Space complexity: O(1)
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minVal = prices[0];
        int size = prices.size();
            
        for (int i = 1; i < size; i++) {
            int currProf = prices[i] - minVal;
            maxProf = max(maxProf, currProf);
            minVal = min(minVal, prices[i]);
        }
        
        return maxProf;
    }
};