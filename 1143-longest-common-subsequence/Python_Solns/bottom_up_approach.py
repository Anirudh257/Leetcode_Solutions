# Time complexity: O(N^2), Space complexity: O(N^2)

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        size1 = len(text1)
        size2 = len(text2)

        self.dp = [[-1 for _ in range(size2 + 1)] for _ in range(size1 + 1)]

        for ind1 in range(size1 + 1):
            self.dp[ind1][0] = 0

        for ind2 in range(size2 + 1):
            self.dp[0][ind2] = 0

        for ind1 in range(1, size1):
            for ind2 in range(1, size2):
                ch1 = text1[ind1 - 1]
                ch2 = text2[ind2 - 1]
 
                curr_lcs_len = float('-inf')
                if ch1 == ch2:
                    curr_lcs_len = 1 + self.dp[ind1 - 1][ind2 - 1]
                else:
                    curr_lcs_len = max(self.dp[ind1 - 1][ind2], self.dp[ind1][ind2 - 1])
        
                self.dp[ind1][ind2] = curr_lcs_len

        return self.dp[size1 - 1][size2 - 1]
        # return self.compLCSLen(text1, text2, size1 - 1, size2 - 1)

    def compLCSLen(self, text1: str, text2: str, ind1 : int, ind2: int) -> int:

        if ind1 < 0 or ind2 < 0:
            return 0

        if self.dp[ind1][ind2] != -1:
            return self.dp[ind1][ind2]

        ch1 = text1[ind1]
        ch2 = text2[ind2]
        
        curr_lcs_len = float('-inf')
        if ch1 == ch2:
            curr_lcs_len = 1 + self.compLCSLen(text1, text2, ind1 - 1, ind2 - 1)
        else:
            curr_lcs_len = max(self.compLCSLen(text1, text2, ind1 - 1, ind2), self.compLCSLen(text1, text2, ind1, ind2 - 1))

        self.dp[ind1][ind2] = curr_lcs_len

        return self.dp[ind1][ind2]