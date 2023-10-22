# Time complexity: O(n*n!), Space complexity: O(n) + Auxiliary Space: O(n)
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def comp_perms(perm, visited, perms):
            if len(perm) == size:

                # Need to add ":" as we want to add all the elements 
                # in current "perm" and not the reference.
                # As perm can become null at some iteration.
                perms.append(perm[:])
                return

            for i in range(size):
                # Skip as already visited
                if visited[i]: 
                    continue

                perm.append(nums[i])
                visited[i] = True
                comp_perms(perm, visited, perms)
                perm.pop()
                visited[i] = False

        perms = []
        size = len(nums)

        comp_perms([], [False]*size, perms)

        return perms