# Time complexity: O(n^2), Space complexity: O(n^2) [DP]

class Solution:

    def cutRod(self, price):

        n = len(price)

        self.dp = [[-1 for _ in range(n + 1)] for _ in range(n)]

        for len_ind in range(0, n + 1):
            self.dp[0][len_ind] = len_ind*price[0]

        for ind in range(1, n):
            for rem_rod_len in range(0, n + 1):

                # If we don't take the rod at that particular length, this means that we will
                # take the next length ind - 1
                not_take = 0 + self.dp[ind - 1][rem_rod_len]

                # If we decide to cut the current rod length, then we need to cut from the overall rod_len.

                take = float('-inf')
                curr_rod_len = ind + 1

                if curr_rod_len <= rem_rod_len:
                    take = price[ind] + self.dp[ind][rem_rod_len - curr_rod_len]

                self.dp[ind][rem_rod_len] = max(take, not_take)

        return self.dp[n - 1][n]

def main():
    price = [1, 5, 8, 9, 10, 17, 17, 20]
    sol = Solution()

    max_rod_val = sol.cutRod(price)

    print("Maximum price possible after cutting the rods is {}".format(max_rod_val))

if __name__ == "__main__":
    main()