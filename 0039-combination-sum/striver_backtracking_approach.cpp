// Time complexity:2^n*k for recursion, Space complexity: O(number of combinations)*k, k = average length of string
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        int size = candidates.size();
        vector<int> comb;


        compCombs(combs, candidates, target, 0, size, comb);

        return combs;
    }
private:
    void compCombs(vector<vector<int>>& combs, vector<int>& candidates, int target, int ind, int size, vector<int>& comb) {

        if (ind >= size) {
            if (target == 0) {
                combs.push_back(comb);
            }
            return;
        }
        
        // Take
        if (target >= candidates[ind]) {
            comb.push_back(candidates[ind]);
            compCombs(combs, candidates, target - candidates[ind], ind, size, comb);
            // Pop when we go to previous state.
            comb.pop_back();
        }

        // Not taking
        compCombs(combs, candidates, target, ind + 1, size, comb);

        return;
    }
};