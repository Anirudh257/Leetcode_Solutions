// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int minRooms, cnt = 0;
        vector<int> stTimes, endTimes;

        for (auto &x : intervals) {
            stTimes.push_back(x[0]);
            endTimes.push_back(x[1]);
        }

        sort(stTimes.begin(), stTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int s = 0, e = 0, size = intervals.size();

        while(s < size) {
            if (stTimes[s] < endTimes[e]) {
                cnt += 1;
                s++;
            }
            else {
                cnt -= 1;
                e++;
            }
            minRooms = max(minRooms, cnt);
        }

        return minRooms;

    }
};