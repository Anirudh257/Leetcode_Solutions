// Time complexity: O(n*n!), Space complexity: O(n) for occur vector, O(n) for perm and Auxiliary Stack space of O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        vector<vector<int>> perms;
        int size = nums.size();
        vector<bool> occur(size, false);
        compPerms(nums, perms, perm, occur);
        return perms;
    }
private:
    void compPerms(vector<int>& nums, vector<vector<int>>& perms, vector<int>& perm, vector<bool>& occur) {
        if (perm.size() == nums.size()) {
            perms.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!occur[i]) {
                occur[i] = true;
                perm.push_back(nums[i]);
                compPerms(nums, perms, perm, occur);
                occur[i] = false;
                perm.pop_back();
            }
        }
    }
};