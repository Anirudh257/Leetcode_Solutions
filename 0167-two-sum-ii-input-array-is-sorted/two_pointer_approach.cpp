// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int l = 0, r = size - 1;
        int sum = numbers[l] + numbers[r];

        while(sum != target && l < r) {
            if (sum > target) {
                r--;
            }
            else if (sum < target) {
                l++;
            }
            sum = numbers[l] + numbers[r];
        }
        return {l + 1, r + 1};
    }
};