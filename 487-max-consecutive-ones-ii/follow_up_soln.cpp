class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        // Time complexity: O(N), Space complexity: O(1)
        
        int zeroInd = -1, st = 0, end = 0, size = nums.size(), maxConsOnes = 0;
        
        while(end < size) {
            if (nums[end] == 0) {
                st = zeroInd + 1;
                zeroInd = end;
            }
            maxConsOnes = max(maxConsOnes, end - st + 1);
            end++;
        }
        return maxConsOnes;
    }
};
