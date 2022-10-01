class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // Time complexity: O(N), Space complexity: O(1)
        int size = arr.size();
        int length = size - 1, numDups = 0;
        
        for (int left = 0; left <= length - numDups; left++) {
            if (arr[left] == 0) {
                if (left == length - numDups) {
                      arr[length] = 0;
                      length-=1;
                      break;
                }
                numDups++;
            }
        }
        
        int last = length - numDups;
        
        for (int i = last; i >= 0; i--) {
              if (arr[i] == 0) {
                    arr[i + numDups] =0;
                    numDups--;
                    arr[i + numDups] = 0;
              }
              else {
                    arr[i + numDups] = arr[i];
              }
        } 
                  
    }
};

