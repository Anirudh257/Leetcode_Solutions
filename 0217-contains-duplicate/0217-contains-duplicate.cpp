class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqNums;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            
            if (uniqNums.find(num) != uniqNums.end()) {
                return true;
            }
            
            uniqNums.insert(num);
        }
        return false;
    }
};