// Time complexity: O(32N), Space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int ans = 0, shift = 1;

        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (int num : nums) {
                if (num & shift) {
                    bitSum += 1;
                }
            }
            // When >= 3 occurences of same bit
            if (bitSum % 3 != 0) {
                ans += shift;
            }
            shift = shift << 1;
        }

        return ans;
    }
};