class Solution {
public:
    // Time complexity: O(NlogN), Space complexity: O(N)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedItvls;
        int size = intervals.size();
        if (size == 0) {
            return mergedItvls;
        }

        sort(intervals.begin(), intervals.end());

        vector<int> tempItv = intervals[0];

        for (auto it : intervals) {
            if (it[0] <= tempItv[1]) {
                tempItv[1] = max(tempItv[1], it[1]);
            }
            else {
                mergedItvls.push_back(tempItv);
                tempItv = it;
            }
        }

        mergedItvls.push_back(tempItv);


        return mergedItvls;
    }
};