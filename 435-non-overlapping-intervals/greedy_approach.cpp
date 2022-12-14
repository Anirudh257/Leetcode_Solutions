// Time complexity: O(nlogn), Space complexity: O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int numItv = 0;

        int prevEnd = intervals[0][1];
        int size = intervals.size();

        for (int i = 1; i < size; i++) {
            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            }
            else {
                prevEnd = min(prevEnd, intervals[i][1]);
                numItv++;
            }
        }

        return numItv;
    }
};
