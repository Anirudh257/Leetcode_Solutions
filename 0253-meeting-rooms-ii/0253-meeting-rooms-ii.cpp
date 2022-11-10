class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        
        if (size == 1) {
            return 1;
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(intervals[0][1]);
        
        for (int i = 1; i < size; i++) {
            vector<int> itv = intervals[i];
            
            int top = pq.top();
            if (top <= itv[0]) {
                pq.pop();
            }
            pq.push(itv[1]);
            
        }
        
        
        return pq.size();
    }
private:
    static bool cmp2(int x, int y) {
        if (x < y) {
            return true;
        }
        return false;
    }
    
    static bool cmp(vector<int>& itv1, vector<int>& itv2) {
        if (itv1[0] < itv2[0]) {
            return true;
        }
        else {
            if (itv1[0] == itv2[0]) {
                return itv1[1] < itv2[1];
            }
        }
        return false;
    }
};