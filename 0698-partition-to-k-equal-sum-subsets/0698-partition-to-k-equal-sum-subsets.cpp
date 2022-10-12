class Solution {
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, 
                   int targetSum, string& taken, unordered_map<string, bool>& memo) {

        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
        
        // If we have already computed the current combination.
        if (memo.find(taken) != memo.end()) {
            return memo[taken];
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return memo[taken] = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, memo);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (taken[j] == '0') {
                // Include this element in current subset.
                taken[j] = '1';
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, memo)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = '0';
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return memo[taken] = false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        sort(arr.begin(), arr.end(), greater<int>());
        
        int targetSum = totalArraySum / k;
        
        // String to represent taken array.
        string taken(n, '0');
        
        // Memoize the ans using taken element's string as key.
        unordered_map<string, bool> memo;
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
    }
};