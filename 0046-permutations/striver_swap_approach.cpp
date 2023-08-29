// Time complexity: O(n*n!), Space complexity: Auxiliary stack space: O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        compPerms(perms, 0, nums);
        return perms;
    }
private:
    void compPerms(vector<vector<int>>& perms, int ind, vector<int>& nums) {
        if (ind == nums.size()) {
            perms.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            swap(nums[i], nums[ind]);
            compPerms(perms, ind + 1, nums);
            swap(nums[i], nums[ind]);
        }
    }
};