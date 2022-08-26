class Solution {
public:
    
    struct cmp{
        constexpr bool operator()(pair<int, int>const& a, pair<int, int>const& b) const noexcept {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            else {
                return a.second > b.second;
            }
        }        
    };

    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> maxVals;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
        
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        
        // while(!pq.empty()) {
        //     cout << pq.top().first << " " << pq.top().second << endl;
        //     pq.pop();
        // }
        
        
        auto top = pq.top();
        int elem = top.first;
        int ind = top.second;
        
        maxVals.push_back(elem);
        
        if (ind == 0) {
            pq.pop();
        }
        
        for (int i = k; i < size; i++) {
            pq.push({nums[i], i});
            auto top = pq.top();
            int elem = top.first;
            int ind = top.second;

            
            while (ind <= i - k) {
                pq.pop();
                auto top = pq.top();
                elem = top.first;
                ind = top.second;
            }        
            
            maxVals.push_back(elem);
    
        }
        
        
        
        return maxVals;
    }
};