// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // For each ith day, if sell on this day, check which day from (0, .. ith) can the cost
        // be minimum
        int minNow = prices[0], size = prices.size();
        int maxProf = 0;

        for (int i = 1; i < size; i++) {
            int cost = prices[i] - minNow;
            maxProf = max(maxProf, cost);
            minNow = min(minNow, prices[i]);
        }

        return maxProf;
    }
};