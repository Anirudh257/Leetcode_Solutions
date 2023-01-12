// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        for (int n : nums) {
            if (n < 0) {
                neg++;
            }
            else if (n > 0){
                pos++;
            }
        }
        return max(neg, pos);
    }
};
