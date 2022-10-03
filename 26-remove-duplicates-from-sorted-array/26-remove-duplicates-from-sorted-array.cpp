class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int size = nums.size();
        
        if (size == 1) {
            return size;
        }
        
        int numUniq = 1;
        
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i - 1]) {
                numUniq++;
            }
        }
        
        int i = 1, j = 1, numCurr = nums[0];
        
        for (; i < numUniq; ) {
            if (numCurr == nums[j]) {
                j++;
            }
            else {
                nums[i] = nums[j];
                numCurr = nums[i];
                
                i++;
                j++;                
            }
            
        }
        
        return numUniq;
        
    }
};