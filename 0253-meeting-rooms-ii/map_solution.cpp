// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> timings;
        unordered_map<int, int> freqOpen;
        unordered_map<int, int> freqClose;

        int minRooms = INT_MIN, currRooms = 0;
        for (auto &x : intervals) {
            timings[x[0]] = 1;
            timings[x[1]] = -1;
            freqOpen[x[0]]++;
            freqClose[x[1]]++;
        }

        for (auto &x : timings) {
            currRooms += freqOpen[x.first] - freqClose[x.first];
            minRooms = max(minRooms, currRooms);
        }

        return minRooms;

    }
};