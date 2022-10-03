class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        int insInd = 1, size = nums.size();
        
        for (int i = 1; i < size; i++) {
            if (nums[i - 1] != nums[i]) {
                nums[insInd] = nums[i];
                insInd++;
            }
        }
        return insInd;
    }
};
