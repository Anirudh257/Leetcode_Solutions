class Solution {
public:
    // Time complexity: O(nlogn), Space complexity: O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for (auto &x : nums) {
            res.push_back(x*x);
        }
        
        sort(res.begin(), res.end());
        
        return res;
        
    }
};