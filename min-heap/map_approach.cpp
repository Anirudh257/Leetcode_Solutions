// Time complexity: O(N*logN), Space complexity: O(N)

#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> reqHeap;
    map<int, int> elemHeap;

    for (auto &x : q) {
        if (x.size() == 2) {
            int elem = x[1];
            elemHeap[elem] += 1;
        }
        else {
            map<int, int>::iterator iter = elemHeap.begin();
            int elem = iter->first;
            int freq = iter->second;
            elemHeap[elem]--;
            if (elemHeap[elem] == 0) {
                elemHeap.erase(elem);
            }
            reqHeap.push_back(elem);
        }
    }

    return reqHeap;
}
