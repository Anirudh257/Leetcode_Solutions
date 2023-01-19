// Time complexity: O(38*len(days)), Space complexity: O(len(days))
// 38 = 1 + 7 + 30 passes through the days
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        int costSize = costs.size();
        vector<int> dp(366, -1);
        return compCost(days, costs, 0, dp);   
    }
private:
    int compCost(vector<int>& days, vector<int>& costs, int dayInd, vector<int>& dp) {
        int numDays = days.size();
        if (dayInd >= numDays) {
            return 0;
        }
        if (dp[dayInd] != -1) {
            return dp[dayInd];
        }

        // Case 1: When buy ticket for 1 day
        int costDay = costs[0] + compCost(days, costs, dayInd + 1, dp);

        // Case 2: When buy ticket for entire week, skip all days days[dayInd], ... days[dayInd] + 7
        int finDay = days[dayInd] + 7;
        
        int st;
        for (st = dayInd; st < numDays && days[st] < finDay; st++);
        int costWeek = costs[1] + compCost(days, costs, st, dp);

        // Case 3: When buy ticket for entire month, skip all days days[dayInd], ... days[dayInd] + 30
        finDay = days[dayInd] + 30;
        
        st = 0;
        for (st = dayInd; st < numDays && days[st] < finDay; st++);
        int costMonth = costs[2] + compCost(days, costs, st, dp);

        return dp[dayInd] = min({costDay, costWeek, costMonth});
    }
};
