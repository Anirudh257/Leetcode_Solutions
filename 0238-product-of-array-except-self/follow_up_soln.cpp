class Solution {
public:
    // Time complexity: O(N), Space complexity: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        // vector<int> leftProd(size, 1);
        // vector<int> rightProd(size, 1);
        vector<int> finProd(size, 1);
   
        int leftVal = 1;
        for (int i = 1; i < size; i++) {
            finProd[i] = nums[i - 1]*leftVal;
            leftVal = finProd[i];
        }
        
        // for (auto &x : finProd) {
        //     cout << x << endl;
        // }
        
        int rightVal = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            finProd[i] = finProd[i]*rightVal;
            rightVal*= nums[i];
        }
        
//         for (int i = 1; i < size; i++) {
//             leftProd[i] = nums[i - 1]*leftProd[i - 1];
//         }
        
//         for (int i = size - 2; i >= 0; i--) {
//             rightProd[i] = nums[i + 1]*rightProd[i + 1];
//         }
        
//         for (int i = 0; i < size; i++) {
//             finProd[i] = leftProd[i]*rightProd[i];
//         }
        
        return finProd;
    }
};
