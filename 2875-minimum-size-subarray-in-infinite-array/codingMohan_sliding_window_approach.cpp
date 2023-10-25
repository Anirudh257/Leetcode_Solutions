// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int size = nums.size();
        int minLen = INT_MAX;
        long long int totSum = 0;
        for (auto &x : nums) {
            totSum += x;
        }

        // There are 3 cases: 
        // sum > target: Just sliding window within 2 copies of array is fine.
        // 2  copies are required for cases when the best subarray sum might lie in between the arrays.
        // sum == target: length of the array
        // sum < target: Need to take multiple copies of array + repeat for
        // new_target: sum%target

        if (totSum == target) {
            minLen = size;
        }
        else if (totSum > target) {
            // Stack a copy of the array at the end of other one.
            vector<int> cp = nums;
            for (auto &x : nums) {
                cp.push_back(x);
            }
            minLen = compMinSub(cp, target, 2*size);

        }
        else {
            minLen = (target/totSum)*size;
            target = target % totSum;
            vector<int> cp = nums;
            for (auto &x : nums) {
                cp.push_back(x);
            }

            int newLen = compMinSub(cp, target, 2*size);
            if (newLen != -1) {
                minLen += newLen;
            }
            else {
                return -1;
            }
        }


        return minLen == INT_MAX ? -1 : minLen;
    }
private:
    int compMinSub(vector<int>& nums, int target, int size) {
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int currSum = 0;
        while(r < size) {
            currSum += nums[r];
            r++;
            while (currSum > target) {
                currSum -= nums[l];
                l++;
            }
            if (currSum == target) {
                minLen = min(r - l, minLen);
            }
        }

        return minLen == INT_MAX ? -1 : minLen;
    }

};