// Time complexity: O(nlogk) as max size of heap is limited to k
// Space complexity: O(k) as max size of heap is limited to k
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (auto &x :nums) {
            pq.push(-x);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return -pq.top();
    }
};