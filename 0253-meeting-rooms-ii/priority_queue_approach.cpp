// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    class cmp {
    public:
        bool operator()(int fir, int sec) {
            return fir > sec;
        }
    };

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int minRooms = 0, currCnt = 0, size = intervals.size();
        priority_queue<int, vector<int>, cmp> pq;

        sort(intervals.begin(), intervals.end());

        pq.push(intervals[0][1]);

        for (int i = 1; i < size; i++) {
            int currSt = intervals[i][0];

            if (currSt >= pq.top()) {
                pq.pop();
            }

            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};