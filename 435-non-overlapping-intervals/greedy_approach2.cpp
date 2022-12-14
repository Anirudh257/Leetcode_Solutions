// Time complexity: O(nlogn), Space complexity: O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int numItv = 0;
        vector<int> prev = intervals[0];

        for (int i = 1; i < size; i++) {
            if (intervals[i][0] >= prev[1]) {
                prev = intervals[i];
            }
            else {
                numItv++;
            }
        }
    
        return numItv;
    }
private:
    bool static cmp(vector<int>& itv1, vector<int>& itv2) {
        return itv1[1] < itv2[1];
    }
};
