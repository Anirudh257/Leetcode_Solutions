class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Time complexity: O(n), Space complexity: O(1)
        int peak = INT_MAX;
        int valley = peak;
        int maxProf = 0;
        int size = prices.size();
        
        for (int i = 0; i < size; i++) {
            if (prices[i] < peak) {
                maxProf += peak - valley;
                peak = valley = prices[i];
            }
            else {
                peak = prices[i];
            }
        }
        maxProf += peak - valley;
        
        return maxProf;
    }
};
