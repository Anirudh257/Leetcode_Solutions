class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int reqSum = 0;
        
        vector<vector<int>> subs;
        
        vector<int> sub;
        compSubs(nums, subs, 0, sub);
        
        for (auto &sub : subs) {
            if (sub.size() == 0) {
                continue;
            }
            int subSum = sub[0];
            
            for (int i = 1; i < sub.size(); i++) {
                subSum ^= sub[i];                
            }
            reqSum += subSum;
        }
        
        return reqSum;
    }
private:
    void compSubs(vector<int>& nums, vector<vector<int>>& subs, int ind, vector<int>& sub) {
        if (ind == nums.size()) {
            subs.push_back(sub);
            return;
        }
        
        vector<int> subNoPick = sub;
        vector<int> subPick = sub;
        subPick.push_back(nums[ind]);
        
        compSubs(nums, subs, ind + 1, subNoPick);
        compSubs(nums, subs, ind + 1, subPick);
        
        return;
    }
};