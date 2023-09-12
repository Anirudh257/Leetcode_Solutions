// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int reqElem;

        for (auto &x : nums) {
            pq.push(x);
        }

        for (int i = 0; i < k; i++) {
            reqElem = pq.top();
            pq.pop();
        }

        return reqElem;
    }
};