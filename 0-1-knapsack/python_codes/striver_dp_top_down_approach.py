class Solution:
    def init_dp_arr(
		self,
        num_rows,
		num_cols,
		init_val
    ):
        dp = [[init_val for _ in range(num_cols)] for _ in range(num_rows)]
        return dp

    def comp_knapsack(
        self,
        value, 
        weight, 
        W: int,
        ind: int,
        dp        
    ):
        if ind == 0:
            if weight[0] <= W:
                return value[0]
            else:
                return 0

        if dp[ind][W] != -1:
            return dp[ind][W]
        else:
            take = float('-inf')
            if W >= weight[ind]:
                take = value[ind] + self.comp_knapsack(
                    value = value,
                    weight = weight,
                    W = W - weight[ind],
                    ind = ind - 1,
                    dp = dp
                )
            not_take = self.comp_knapsack(
                    value = value,
                    weight = weight,
                    W = W,
                    ind = ind - 1,
                    dp = dp
                )
            dp[ind][W] = max(take, not_take)

        return dp[ind][W]


    def knapsack(self, W, val, wt):
        n = len(val)

        dp = self.init_dp_arr(n, W + 1, -1)
        return self.comp_knapsack(val, wt, W, n - 1, dp)
        
