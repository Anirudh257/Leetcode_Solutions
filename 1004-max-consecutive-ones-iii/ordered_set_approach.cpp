class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(N)
        // Ordered set approach
        set<int> ordNums;
        
        for (int n : nums) {
            if (ordNums.count(n)) {
                continue;
            }
            if (ordNums.size() == 3) {
                if (n > *ordNums.begin()) {
                    ordNums.erase(ordNums.begin());
                    ordNums.insert(n);
                }
            }
            else {
                ordNums.insert(n);
            }
        }
        
        if (ordNums.size() != 3) {
            return *ordNums.rbegin();
        }
        return *ordNums.begin();
    }
};
