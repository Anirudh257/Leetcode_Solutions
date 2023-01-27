// Time complexity: O(N), Space complexity: O(k)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> rems(k, 0);
        int sum = 0;

        for (int n : nums) {
            sum += (n%k + k)%k; // convert negative value to positive.
            rems[sum%k]++;
        }

        int res = rems[0]; // 0 can be used as it is divisible by any k

        for (int c : rems) {
            res += (c*(c - 1))/2;
        }

        return res;
    }
};
