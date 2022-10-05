class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        vector<int> dup;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            int ind = abs(num) - 1;
            
            if (nums[ind] > 0) {
                nums[ind] *= -1;
            }
            else {
                dup.push_back(abs(num));
            }
        }
        
        return dup;
    }
};