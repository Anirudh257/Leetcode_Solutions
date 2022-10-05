class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        // Time complexity: O(N), Space complexity: O(1)
        
        long long firstMax = numeric_limits<long long>::min();
        long long secMax = numeric_limits<long long>::min();
        long long thirdMax = numeric_limits<long long>::min();
        
        for (int n : nums) {
            if (firstMax == n || secMax == n || thirdMax == n) {
                continue;
            }
            if (firstMax <= n) {
                thirdMax = secMax;
                secMax = firstMax;
                firstMax = n;
            }
            else if (secMax <= n) {
                thirdMax = secMax;
                secMax = n;
            }
            else if (thirdMax <= n) {
                thirdMax = n;
            }
        }
        
        if (thirdMax == numeric_limits<long long>::min()) {
            return firstMax;
        }
        
        return thirdMax;
        
    }
};
