class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        vector<int> missNums;
        int size = nums.size();
        
        for (int n : nums) {
            int ind = n - 1;
            
            while(nums[n - 1] != n) {
                swap(n, nums[n - 1]);
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                missNums.push_back(i + 1);
            }
        }
        
        return missNums;
    }
};
