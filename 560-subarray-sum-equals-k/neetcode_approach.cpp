// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Save prefix sums at each iteration to count the number of required subarrays
        int numSub = 0, size = nums.size(), sum = 0;
        unordered_map<int, int> prefCount;
        prefCount[0] = 1; // Array of 0 elements sums up to 0

        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (prefCount.count(sum - k)) {
                numSub += prefCount[sum - k];
            }
            prefCount[sum]++;

        }

        return numSub;
    }
};
