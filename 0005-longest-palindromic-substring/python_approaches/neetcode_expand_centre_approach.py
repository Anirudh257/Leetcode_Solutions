# Time complexity: O(n^2)
# Space complexity: O(1)

class Solution:
    def comp_pal_len(
        self, 
        s: str, 
        l: int, 
        r : int, 
        n: int, 
        max_pal_len: int,
        res: str
    ) -> int:
        while l >= 0 and r < n and s[l] == s[r]:
            curr_len = r - l + 1
            if curr_len > max_pal_len:
                max_pal_len = curr_len
                res = s[l:r + 1]
            l -= 1
            r += 1
        
        return max_pal_len, res

    def longestPalindrome(self, s: str) -> str:
        # Expand from centre to avoid repeated substring checks.

        n = len(s)
        res = ""
        max_pal_len = 0

        for i in range(n):
            
            # Odd-length palindromes.
            max_pal_len, res = self.comp_pal_len(
                s = s, 
                l = i, 
                r = i, 
                n = n,
                max_pal_len = max_pal_len, 
                res = res
            )

            # Even-length palindromes.
            max_pal_len, res = self.comp_pal_len(
                s = s, 
                l = i, 
                r = i + 1, 
                n = n,
                max_pal_len = max_pal_len, 
                res = res
            )

        return res