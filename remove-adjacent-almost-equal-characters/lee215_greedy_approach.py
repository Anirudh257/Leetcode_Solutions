# Time complexity: O(N), Space complexity: O(1)
class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:
        size = len(word)
        num_rem = 0
        i = 1
        while i < size:
            prev = word[i - 1]
            curr = word[i]
            
            # ord => returns the unicode of the character.
            if abs(ord(curr) - ord(prev)) <= 1:
                num_rem += 1
                i += 2 # skip to avoid double check of adjacency.
            else:
                i += 1

        return num_rem