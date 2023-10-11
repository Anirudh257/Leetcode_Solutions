// Time complexity: O(N log N), Space complexity: O(N)
struct meeting {
  int stTime;
  int endTime;
  int pos;  
};

bool comparator(struct meeting m1, struct meeting m2) {
    if (m1.endTime < m2.endTime) {
        return true;
    }
    else if (m1.endTime > m2.endTime) {
        return false;
    }
    else if (m1.pos < m2.pos){
        return true;
    }
    return false;
}

int maximumMeetings(vector<int> &start, vector<int> &end){
    int size = start.size();
    struct meeting meet[size];
    for (int i = 0; i < size; i++) {
        meet[i].stTime = start[i];
        meet[i].endTime = end[i];
        meet[i].pos = i;
    }

    sort(meet, meet + size, comparator);
    
    int maxTime = meet[0].endTime;
    int maxMeet = 1;
    for (int i = 1; i < size; i++) {
        if (meet[i].stTime > maxTime) {
            maxMeet++;
            maxTime = meet[i].endTime;
        }
    }
    
    return maxMeet;
}