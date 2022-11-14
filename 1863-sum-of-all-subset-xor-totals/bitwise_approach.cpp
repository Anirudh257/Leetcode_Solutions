class Solution {
public:
    // Time complexity: O(n*2^n), Space complexity: O(1)
    int subsetXORSum(vector<int>& nums) {
        int reqSum = 0;
        int size = nums.size();
        int numSubs = pow(2, size);
        
        for (int sub = 1; sub < numSubs; sub++) {
            int subSum = 0;
            for (int i = 0, bits = sub; i < size; i++, bits >>= 1) {
                if (bits & 1) {
                    subSum ^= nums[i];
                }
            }
            reqSum += subSum;
        }
        
        return reqSum;
    }
};
