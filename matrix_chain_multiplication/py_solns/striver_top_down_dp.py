# TC: O(n^3)
# SC: O(n*2) + Auxiliary stack space O(n)

# GeeksforGeeks link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution:
    
    def init_dp_arr(self, rows, cols, init_val):
        dp = [[init_val for _ in range(cols)] for _ in range(rows)]
        return dp
    
    def comp_mc_operns(self, arr, i, j, dp):
        
        # Base case:
        if i == j:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        min_steps = 1e9
        for k in range(i, j):
                    # num_steps to multiply the final matrix
                    # + num_steps to multiply the 2 sub-matrices separately.
            steps = arr[i-1]*arr[k]*arr[j] + self.comp_mc_operns(arr, i, k, dp) + self.comp_mc_operns(arr, k + 1, j, dp)
            
            min_steps = min(min_steps, steps)
        dp[i][j] = min_steps
        return min_steps
    
    def matrixMultiplication(self, arr):
        # code here
        
        n = len(arr)
        dp = self.init_dp_arr(n, n, -1)
        return self.comp_mc_operns(arr, 1, n - 1, dp)