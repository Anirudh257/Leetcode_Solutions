// Time complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> disNums;

        vector<int> cp = nums;

        for (int n : cp) {
            int ind = abs(n) - 1;
            cp[ind] = -1*abs(cp[ind]);
        }

        for (int i = 0; i < size; i++) {
            int n = cp[i];
            if (n > 0) {
                disNums.push_back(i + 1);
            }
        }

        return disNums;
    }
};
