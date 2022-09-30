class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        // Time complexity: O(N), Space complexity: O(1)
        for (int n : nums){
            res += (int)log10(n) & 1;
        }
        
        return res;
    }
private:
    int numDig(int num) {
        int ans = 0;
        
        while(num) {
            num = num/10;
            ans++;
        }
        return ans;
    }
};
