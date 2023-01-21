// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int prev2 = 0, prev = nums[0], curr = 0;

        for (int ind = 1; ind < size; ind++) {
            int take = nums[ind];

            if (ind > 1) {
                take += prev2;
            }

            int notTake = prev;

            curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        } 


        return prev;
    }
};
