class Solution:
    
    def compMaxSubArrSum(self, nums: List[int], l: int, r: int) -> int:
        if l == r:
            return nums[l]
        else:
            m = (l + r)//2
            leftSubSum = self.compMaxSubArrSum(nums, l, m)
            rightSubSum = self.compMaxSubArrSum(nums, m + 1, r)

            bestCrossSum = self.compCrossSum(nums, l, r, m)

        return max({leftSubSum, rightSubSum, bestCrossSum})

    def compCrossSum(self, nums: List[int], l: int, r: int, m: int) -> int:

        bestLeftSum = -1e9
        leftSum = 0

        for i in range(m, l - 1, -1):
            leftSum += nums[i]
            bestLeftSum = max(leftSum, bestLeftSum)

        bestRightSum = -1e9
        rightSum = 0

        for i in range(m + 1, r + 1):
            rightSum += nums[i]
            bestRightSum = max(rightSum, bestRightSum)

        return bestLeftSum + bestRightSum

    def maxSubArray(self, nums: List[int]) -> int:

        return self.compMaxSubArrSum(nums, 0, len(nums) - 1)

