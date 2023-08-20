# Time complexity: O(N), Space complexity: O(1)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        if not head.next:
            return head

        curr = head
        n = 1

        while curr.next:
            n += 1
            curr = curr.next

        curr.next = head

        k = k%n
        k = n - k
        # print(k)
        # print(head.val)

        new_head = head
        while k > 1:
            k -= 1
            new_head = new_head.next

        temp = new_head.next

        new_head.next = None
        
        return temp