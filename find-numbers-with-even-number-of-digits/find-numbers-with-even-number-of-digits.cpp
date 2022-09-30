class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        
        // cout << numDig(34343);
        for (int n : nums) {
            if (numDig(n) % 2 == 0) {
                res++;
            }
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