# Time complexity: O(N), Space complexity: O(N)
class Solution:
    def isValid(self, s: str) -> bool:
        
        size = len(s)
        
        if size % 2 != 0:
            return False
        
        stack = []
        
        for ch in s:
            if len(stack) == 0:
                stack.append(ch)
            else:
                st_top = stack[-1]
                if st_top == "(" and ch == ")":
                    stack.pop()
                elif st_top == "[" and ch == "]":
                    stack.pop()
                elif st_top == "{" and ch == "}":
                    stack.pop()
                else:
                    stack.append(ch)
                
        return len(stack) == 0