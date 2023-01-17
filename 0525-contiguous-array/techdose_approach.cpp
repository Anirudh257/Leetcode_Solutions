// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size(), sum = 0;
        int maxLen = 0;

        // prefix Map logic with -1 instead of 0 while adding and recheck if present in the 
        // map

        unordered_map<int, int> prefSumInd;

        for (int i = 0; i < size; i++) {
            int num = nums[i];
            if (num) {
                sum++;
            }
            else {
                sum--;
            }
            if (prefSumInd.find(sum) == prefSumInd.end()) {
                prefSumInd[sum] = i;
            }
            else {
                // From previous occurence of same sum, compute the distance
                int currLen = i - prefSumInd[sum];
                maxLen = max(currLen, maxLen);
            }
            // Adding from 0 till current index gave sum = 0 => equal number of 0s and 1s.
            if (sum == 0) {
                int currLen = i + 1;
                maxLen = max(currLen, maxLen);
            }
        }


        return maxLen;
    }
};
