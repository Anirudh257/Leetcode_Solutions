# Time complexity: O(N), Space complexity: O(1)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None

        slow = head
        fast = head
        entry = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                break

        
        if not fast or not fast.next:
            return None

        while entry != slow:
            entry = entry.next
            slow = slow.next

        if slow:
            return slow
 
        return None