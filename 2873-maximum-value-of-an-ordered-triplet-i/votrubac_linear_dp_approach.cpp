// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // Objective is to maximize 
        // (a) max_i = nums[i], track biggest number we have found
        // (b) max_ij = nums[i] - nums[j] - track biggest difference.
        // (c) max_ij*nums[k]
        // such that i < j < k

        int size = nums.size();
        long long res = 0, max_ij = nums[0] - nums[1], max_i = nums[0];

        for (int k = 2; k < size; k++) {
            res = max(res, max_ij*nums[k]);
            max_i = max(max_i, (long long)nums[k - 1]);
            max_ij = max(max_ij, max_i - nums[k]);
        }

        return res;
    }
};