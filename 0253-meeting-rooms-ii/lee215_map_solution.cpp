// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> changes;
        int res = 0, cur = 0;

        for (auto &x : intervals) {
            changes[x[0]]++;
            changes[x[1]]--;
        }

        for (auto &x : changes) {
            cur += x.second;
            res = max(res, cur);
        }

        return res;
    }
};
