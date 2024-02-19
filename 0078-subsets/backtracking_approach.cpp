// Time complexity: O(2^n), Space complexity: O(2^n) + Auxiliary stack space: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> subs;
        vector<int> sub;

        compSubs(subs, nums, sub, size, 0);

        return subs;
    }
private:
    void compSubs(vector<vector<int>>& subs, vector<int>& nums, vector<int>& sub, int size, int ind) {
        if (ind == size) {
            subs.push_back(sub);
            return;
        }

        // not_take
        compSubs(subs, nums, sub, size, ind + 1);

        // take
        sub.push_back(nums[ind]);
        compSubs(subs, nums, sub, size, ind + 1);
        sub.pop_back();

    }
};