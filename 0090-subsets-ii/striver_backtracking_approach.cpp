// Time complexity: O(2^n*k), Space complexity: O(2^n)*k
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;

        sort(nums.begin(), nums.end());

        int size = nums.size();

        compSubs(subs, sub, size, 0, nums);

        return subs;

    }
private:
    void compSubs(vector<vector<int>>& subs, vector<int>& sub, int& size, int ind, vector<int>& nums) {

        subs.push_back(sub);

        for (int i = ind; i < size; i++) {
            
            // Avoid duplicate, only pick one at a time
            if (ind != i && nums[i] == nums[i - 1]) {
                continue;
            }
            sub.push_back(nums[i]);
            compSubs(subs, sub, size, i + 1, nums);
            sub.pop_back();
        }
    
    }

};