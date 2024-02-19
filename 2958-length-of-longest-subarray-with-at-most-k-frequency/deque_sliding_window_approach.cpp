// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, deque<int>> inds;
        int maxLen = 0, l = 0, r = 0, size = nums.size();

        while(r < size) {
            int num = nums[r];
            if (freq[num] < k) {
                freq[num]++;
                inds[num].push_back(r);
            }
            else {
                l = max(l, inds[num].front() + 1);
                inds[num].pop_front();
                inds[num].push_back(r);
            }
            maxLen = max(r - l + 1, maxLen);
            r++;
        }


        return maxLen;
    }
};