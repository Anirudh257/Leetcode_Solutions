// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prod(size, 1);
        int prefix = 1;

        for (int i = 0; i < size; i++) {
            prod[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = size - 1; i >= 0; i--) {
            prod[i] *= postfix;
            postfix *= nums[i];
        }

        return prod;
    }
};