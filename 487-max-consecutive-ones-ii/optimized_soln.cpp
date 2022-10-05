class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int size = nums.size(), numOnes = 0, numOnesZero = 0, maxConsOnes = 0;
        
        for (int n : nums) {
            if (n == 1) {
                numOnes++;
                numOnesZero++;
            }
            else {
                numOnesZero = numOnes + 1;
                numOnes = 0;
            }
            maxConsOnes = max(maxConsOnes, numOnesZero);
        }
        
        return maxConsOnes;
    }
};
