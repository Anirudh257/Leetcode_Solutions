// Time complexity: O(nlogn) for sorting, O(2^n*k) for recursion, O(n) for set to vector conversion, Space complexity: O(number of combinations). 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subs;
        vector<int> sub;

        sort(nums.begin(), nums.end());

        int size = nums.size();

        compSubs(subs, sub, size, 0, nums);

        return vector<vector<int>>(subs.begin(), subs.end());
    }
private:
    void compSubs(set<vector<int>>& subs, vector<int>& sub, int& size, int ind, vector<int>& nums) {
        if (ind == size) {
            subs.insert(sub);
            return;
        }

        // not take
        compSubs(subs, sub, size, ind + 1, nums);

        // take
        sub.push_back(nums[ind]);
        compSubs(subs, sub, size, ind + 1, nums);
        sub.pop_back();
    }
};