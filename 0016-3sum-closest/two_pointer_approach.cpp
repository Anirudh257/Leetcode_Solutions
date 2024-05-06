// Time complexity: O(nlogn) + O(n^2), Space complexity: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int minDiff = 1e9, diff = 1e9;
        int reqSum = 1e9;

        sort(nums.begin(), nums.end());

        // for (auto &x : nums) {
        //     cout << x << endl;
        // }

        for (int i = 0; i < size; i++) {
            
            int j = i + 1, k = size - 1;            
            while(j!= k && j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    reqSum = sum;
                }

                if (sum > target) {
                    k--;
                }
                else {
                    j++;
                }
                
            }
        }

        return reqSum;

    }
};