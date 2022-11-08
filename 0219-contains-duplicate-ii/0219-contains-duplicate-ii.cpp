class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            if (um.find(num) != um.end()) {
                if (abs(i - um[num]) <= k) {
                    return true;
                }
            }
            um[nums[i]] = i;

        }
        return false;
    }
};