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
        
        
        for (int i = 1; i < size; i++) {
            int currSt = intervals[i][0];
            int currEnd = intervals[i][1];   
            
            if (currSt < maxEnd) {
                return false;
            }
            maxSt = min(maxSt, currSt);
            maxEnd = max(maxEnd, currEnd);
            
        }
        
        return true;
    }
};