# Time complexity: O(n^2), Space complexity: O(n^2)

class Solution:

    def cutRod(self, price):

        n = len(price)

        self.dp = [[-1]*(n + 1)]*n

        return self.compMaxRodVal(price, n, n - 1)

    def compMaxRodVal(self, price, rem_rod_len, ind):

        if ind == 0:
            return price[0]*rem_rod_len
        
        if self.dp[ind][rem_rod_len] != -1:
            return self.dp[ind][rem_rod_len]

        # We can either cut the rod at that particular length or skip.

        # If we don't take the rod at that particular length, this means that we will
        # take the next length ind - 1
        not_take = 0 + self.compMaxRodVal(price, rem_rod_len, ind - 1)

        # If we decide to cut the current rod length, then we need to cut from the overall rod_len.

        take = 1e-9
        rod_len = ind + 1

        if rod_len <= rem_rod_len:
            take = price[ind] + self.compMaxRodVal(price, rem_rod_len - rod_len, ind)

        self.dp[ind][rem_rod_len] = max(take, not_take)

        return self.dp[ind][rem_rod_len]

def main():
    price = [1, 5, 8, 9, 10, 17, 17, 20]
    sol = Solution()

    max_rod_val = int(sol.cutRod(price))

    print("Maximum price possible after cutting the rods is {}".format(max_rod_val))

if __name__ == "__main__":
    main()