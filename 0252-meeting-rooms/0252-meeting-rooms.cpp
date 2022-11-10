class Solution {
public:
    // Time complexity: O(nlogn), Space complexity: O(1)
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int size = intervals.size();
        
        if (size <= 1) {
            return true;
        }
        
        sort(intervals.begin(), intervals.end());
        
        int maxSt = intervals[0][0];
        int maxEnd = intervals[0][1];
        
        
        for (int i = 0; i < size - 1; i++) {
            // int currSt = intervals[i][0];
            // int currEnd = intervals[i][1];   
            
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
            
        }
        
        return true;
    }
};