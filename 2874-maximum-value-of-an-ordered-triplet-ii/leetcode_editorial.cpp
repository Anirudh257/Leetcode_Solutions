// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal = 0;
        int size = nums.size();
        vector<int> prefMax(size, 0);
        vector<int> sufMax(size, 0);

        prefMax[0] = nums[0];
        sufMax.back() = nums.back();

        for (int i = 1; i < size; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        for (int i = size - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], nums[i]);
        }

        for (int k = 1; k < size - 1; k++) {
            long long curVal = (long long)(prefMax[k - 1] - nums[k])*sufMax[k + 1];
            maxVal = max(maxVal, curVal);
        }
        

        return maxVal;
    }
};