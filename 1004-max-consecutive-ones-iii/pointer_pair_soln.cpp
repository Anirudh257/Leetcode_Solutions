class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        // Time complexity: O(N), Space complexity: O(1)
        
        pair<int, bool> firstMax = {-1, false};
        pair<int, bool> secMax = {-1, false};
        pair<int, bool> thirdMax = {-1, false};
        
        for (int n : nums) {
            if (firstMax.second && firstMax.first == n || secMax.second && secMax.first == n || thirdMax.second && thirdMax.first == n) {
                continue;
            }
            if (!firstMax.second || firstMax.first <= n) {
                thirdMax = secMax;
                secMax = firstMax;
                firstMax = {n, true};
            }
            else if (!secMax.second || secMax.first <= n) {
                thirdMax = secMax;
                secMax = {n, true};
            }
            else if (!thirdMax.second || thirdMax.first <= n) {
                thirdMax = {n, true};
            }
        }
        
        if (!thirdMax.second) {
            return firstMax.first;
        }
        
        return thirdMax.first;
        
    }
};
