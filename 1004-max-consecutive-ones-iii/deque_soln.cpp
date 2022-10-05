class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Time complexity: O(N), Space complexity: O(N)
        int r = 0, l = 0, size = nums.size(), maxOnes = 0;
        deque<int> dq;
        
        while(r < size) {
            if (nums[r] == 0) {
                dq.push_back(r);
            }
            if (dq.size() > k) {
                l = dq.front() + 1;
                dq.pop_front();
            }
            maxOnes = max(maxOnes, r - l + 1);
            r++;
        }
        return maxOnes;
    }
};
