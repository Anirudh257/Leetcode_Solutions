// Time complexity: O(NlogN), Space complexity: O(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedItvs;
        int size = intervals.size();

        if (size == 0) {
            return mergedItvs;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        mergedItvs.push_back(intervals[0]);

        for (int i = 1; i < size; i++) {
            if (mergedItvs.back()[1] < intervals[i][0]) {
                mergedItvs.push_back(intervals[i]);
            }
            else {
                mergedItvs.back()[1] = max(mergedItvs.back()[1], intervals[i][1]);
            }
        }


        return mergedItvs;    
    }
};