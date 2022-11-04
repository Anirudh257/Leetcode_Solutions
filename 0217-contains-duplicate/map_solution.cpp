class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        for (int n : nums) {
            umap[n]++;
            if (umap[n] > 1) {
                return true;
            }
        }
        return false;
        
    }
};
