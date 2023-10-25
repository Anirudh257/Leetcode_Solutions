# Time complexity: O(log N), Space complexity: O(1)
class Solution:
    def isHappy(self, n: int) -> bool:
        slow = n
        fast = self.sumOfSquares(n)

        while fast != 1 and slow != fast:
            fast = self.sumOfSquares(self.sumOfSquares(fast))
            slow = self.sumOfSquares(slow)

            if slow == fast:
                break
        
        return fast == 1

 
    def sumOfSquares(self, n:int) -> int:
        tot = 0

        while n:
            dig = n%10
            dig = dig ** 2
            tot += dig
            n = n // 10

        return tot