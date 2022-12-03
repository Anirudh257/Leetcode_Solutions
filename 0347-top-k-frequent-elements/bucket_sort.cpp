class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        
        unordered_map<int, int> numFreq;
        
        for (int n : nums) {
            numFreq[n]++;
        }
        vector<int> res;
        vector<vector<int>> buckets(size + 1);
        
        for (auto [a, b]: numFreq) {
            buckets[b].push_back(a);
        }
        
        for (int i = size ;k; i--) {
            for (auto a: buckets[i]) {
                res.push_back(a);
                k--;   
            }
        }
        
        return res;
    }
};
