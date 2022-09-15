class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int size = prices.size();
        
        // Time complexity: O(N), Space complexity: O(1)
        
        for (int i = 1; i < size; i++) {
            if (prices[i] > prices[i - 1]) {
                prof += prices[i] - prices[i - 1];
            }
        }
        
        return prof;
    }
};
