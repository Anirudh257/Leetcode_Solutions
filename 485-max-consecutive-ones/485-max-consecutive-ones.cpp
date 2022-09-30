class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        // Time complexity: O(N), Space complexity: O(1)
        int maxCons = 0, currCons = 0, size = nums.size();
        bool flag = false;
        
        for (int n : nums) {
            if (n == 1) {
                if (flag) {
                    currCons += 1;                
                }
                else {
                    currCons = 1;
                    flag = true;                    
                }
            }
            else {
                flag = false;
            }
            maxCons = max(maxCons, currCons);
        }
        
        return maxCons;
        
    }
};