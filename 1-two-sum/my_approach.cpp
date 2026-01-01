// Time complexity: O(n^2), Space complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> elemMap;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (elemMap.find(target - nums[i]) != elemMap.end()) {
                return {i, elemMap[target - nums[i]]};
            }
            else {
                elemMap[nums[i]] = i;
            }
        }

        return {};
    }
};