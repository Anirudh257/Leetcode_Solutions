class Solution {
public:

    // Time complexity: O(n^2)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, cmp> pq;
        unordered_map<int, vector<int>> freqNum;
        unordered_map<int, int> numFreq;
        // unordered_map<int, int> indFreq;
        vector<int> res;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            numFreq[num]++;
        }
        
        int maxFreq = INT_MIN;
        
        for (auto &x : numFreq) {
            int freq = x.second;
            int num = x.first;
            freqNum[freq].push_back(num);
            maxFreq = max(maxFreq, freq);
        }        
        
        while(res.size() <= k) {
            if (freqNum.find(maxFreq) != freqNum.end()) {
                vector<int> elems = freqNum[maxFreq];
                
                if (elems.size() == k) {
                    return elems;
                }
                else {
                    for (int elem : elems) {
                        res.push_back(elem);
                        if (res.size() == k) {
                            return res;
                        }
                    }
                }
                
                
            }
            maxFreq--;
        }
        
        
        
        return res;
    }   
private:
};
