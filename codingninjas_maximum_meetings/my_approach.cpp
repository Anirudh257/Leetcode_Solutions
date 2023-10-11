// Time complexity: O(N log N), Space complexity: O(N)
vector<vector<int>> sortStTime(vector<vector<int>>& times) {
    map<int, vector<int>> timeInds;
    int size = times.size();
    for (int i = 0; i < size; i++) {
        timeInds[times[i][1]].push_back(i);
    }

    vector<vector<int>> sortTimes;

    for (auto &x : timeInds) {
        // cout << x.first << " ";
        // for (auto &y : x.second) {
        //     cout << y << " ";
        // }
        for (auto &y : x.second) {
            sortTimes.push_back(times[y]);
        }
        // cout << endl;
    }

    return sortTimes;
}

int maximumMeetings(vector<int> &start, vector<int> &end){
    int size = start.size();
    if (size == 1) {
        return size;
    }
    vector<vector<int>> times;
    for (int i = 0; i < size; i++) {
        vector<int> timest = {start[i], end[i]};
        times.push_back(timest);
    }

    // for (auto &x : times) {
    //     cout << x[0] << " " << x[1] << endl;
    // }

    times = sortStTime(times);

    int maxMeet = 1;
    int st = times[0][0];
    int endTime = times[0][1];
    for (int i = 1; i < size; i++) {
        int currSt = times[i][0];
        int currEnd = times[i][1];
        if (currSt > st && currSt > endTime) {
            maxMeet++;
            st = min(st, currSt);
            endTime = max(endTime, currEnd);
        }
    }


    return maxMeet;
}