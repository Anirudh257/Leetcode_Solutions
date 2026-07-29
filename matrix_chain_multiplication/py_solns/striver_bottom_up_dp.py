# Time complexity: O(n^3)
# Space complexity: O(n^2)

class Solution:
    
    def init_dp_arr(self, rows, cols, init_val):
        dp = [[init_val for _ in range(cols)] for _ in range(rows)]
        return dp
        
    def matrixMultiplication(self, arr):
        # code here
        
        n = len(arr)
        
        # Base case first.
        dp = self.init_dp_arr(n, n, 0)
        
        for i in range(n-1, 0, -1):
            for j in range(i + 1, n):
                min_steps = 1e9
                for k in range(i, j):
                    # num_steps to multiply the final matrix
                    # + num_steps to multiply the 2 sub-matrices separately.
                    steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k + 1][j]
                    
                    min_steps = min(min_steps, steps)
                dp[i][j] = min_steps

        
        return dp[1][n-1]
        