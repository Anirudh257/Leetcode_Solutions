class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;

        // Time complexity: O(32), Space complexity: O(1)

        int bitSetInd = 0;

        // All numbers appear twice except 2 numbers that appear just once
        // So, XOR of all numbers = XOR(diff1, diff2)
        // As diff1 != diff2, we know that they differ at atleast 1 bit
        // And XOR result at that bit = 1(1^0 == 0^1 = 1)
        // Only 2 possibilities exist=> number that has that bit set = 0
        // or bit set = 1
        // Separately XORing bit set = 0 and XORing bit set = 1 ==> relevant
        // numbers. As all other numbers are appearing two times and x^x = 0
        // We get the relevant numbers

        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (auto &x : nums) {
                bitSum ^= (x & (1 << i));
            }
            if (bitSum != 0) {
                bitSetInd = i;
                break;
            }
        }

        int bitInd0 = 0, bitInd1 = 0;

        for (auto &x : nums) {
            if (x & (1 << bitSetInd)) {
                bitInd1 ^= x;
            }
            else {
                bitInd0 ^= x;
            }
        }


        return {bitInd0, bitInd1};
    }
};