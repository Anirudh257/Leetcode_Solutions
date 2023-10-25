# Time complexity: O(log N), Space complexity: O(log N)
class Solution:
    def isHappy(self, n: int) -> bool:
        visit = set()

        while n not in visit:
            visit.add(n)
            n = self.sumOfSquares(n)

            if n == 1:
                return True

        return False

    def sumOfSquares(self, n:int) -> int:
        tot = 0

        while n:
            dig = n%10
            dig = dig ** 2
            tot += dig
            n = n // 10

        return tot