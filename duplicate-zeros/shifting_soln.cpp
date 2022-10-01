class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int shift = count(arr.begin(), arr.end(), 0);
        // Time complexity: O(N), Space complexity: O(1)
        
        for (int i = size - 1; i >= 0; i--) {
            if (!arr[i]) {
                shift--;
            }
            if (i + shift < size) {
                arr[i + shift] = arr[i];
                if (!arr[i] & i + shift + 1 < size) {
                    arr[i + shift + 1] = 0;
                }
            }
        }
        
    }
};
