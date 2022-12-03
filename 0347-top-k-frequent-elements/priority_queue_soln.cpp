class Solution {
public:
    // Time complexity: O(NlogK)
    
    // Space complexity: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }
        vector<int> res;
        
        
        unordered_map<int, int> numFreq;
        for (int n : nums) {
            numFreq[n]++;
        }
        
        auto comp = [&numFreq](int n1, int n2) { return numFreq[n1] > numFreq[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        

        for (auto &x : numFreq) {
            pq.push(x.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

                
        return res;
    }
};
