// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefSumInd;
        int size = nums.size(), prefSum = 0;
        prefSumInd[0] = -1; // To only allow arrays of size >= 2.
        // Just [k], [2*k] won't be allowed.

        if (size <= 1) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            prefSum += nums[i];
            int rem = prefSum%k;
            if (prefSumInd.find(rem) == prefSumInd.end()) {
                prefSumInd[rem] = i;
            }
            else if (i - prefSumInd[rem] > 1){
                return true;
            }
        }

        return false;
    }
};
