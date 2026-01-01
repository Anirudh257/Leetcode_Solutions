# Time complexity: O(2*n), Space complexity: O(n)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        max_len, curr_len = 0, 0
        num_set = set(nums)

        # Avoid re-iterating through same element
        for n in num_set:
            pre = n - 1
            
            # No previous number exists, so this is a potential start of sequence.
            if pre not in num_set:
                curr_len = 0

                # keep checking if consecutive numbers exist in the set and increase
                # the current consecutive sequence length.
                while((n + curr_len) in num_set):
                    curr_len += 1
                
                max_len = max(max_len, curr_len)

        return max_len