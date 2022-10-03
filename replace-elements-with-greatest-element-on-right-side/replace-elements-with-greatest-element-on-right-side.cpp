class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        if (size == 1) {
            return {-1};
        }
        vector<int> maxEnd(size, -1);
        vector<int> res(size, -1);
        int maxElem = arr[size - 1];
        for (int i = size -1; i >= 0; i--) {
            maxElem = max(maxElem, arr[i]);
            maxEnd[i] = maxElem;
        }
        
        for (int i = 0; i < size - 1; i++) {
            res[i] = maxEnd[i + 1];
        }
        
        return res;
    }
};