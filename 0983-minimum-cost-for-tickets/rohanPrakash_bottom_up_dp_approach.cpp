// Time complexity: O(365), Space complexity: O(365)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        int costSize = costs.size();
        vector<int> dp(366, 0);

        unordered_set<int> daySet(days.begin(), days.end());

        for (int dayInd = 1; dayInd < 366; dayInd++) {
            dp[dayInd] = dp[dayInd - 1];
            if (daySet.find(dayInd) != daySet.end()) {
                dp[dayInd] = min({dp[dayInd - 1] + costs[0],
                            dp[max(0, dayInd - 7)] + costs[1],
                            dp[max(0, dayInd - 30)] + costs[2]});
            }
        }

        return dp[365];   
    }
};
