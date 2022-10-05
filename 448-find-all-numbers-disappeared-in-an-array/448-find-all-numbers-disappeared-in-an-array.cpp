class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        vector<int> missNums;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            int newInd = abs(nums[i]) - 1;
            
            if (nums[newInd] > 0) {
                nums[newInd] *= -1;
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                missNums.push_back(i + 1);
            }
        }
        
        return missNums;
    }
};