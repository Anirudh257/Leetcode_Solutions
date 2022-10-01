class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // Time complexity: O(N), Space complexity: O(N)
        int size = arr.size();
        vector<int> res(size, 0);
        int i = 0, j = 0;
        
        while(i < size && j < size) {
            if (arr[i] != 0) {
                res[j] = arr[i];
                i++;
                j++;
            }
            else {
                i++;
                j+=2;
            }
        }
        
        arr = res;
    }
};