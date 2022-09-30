class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(N)
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int n : nums) {
        	pq.push(abs(n));
        }
        
        while(!pq.empty()) {
        	int elem = pq.top();
            pq.pop();
            res.push_back(elem*elem);
        }       
        return res;
    }
};

