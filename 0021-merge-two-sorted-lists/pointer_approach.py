# Time complexity: O(n1 + n2), n1 = len(list1), n2 = len(list2), Space complexity: O(1)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        merged_list = ListNode(-1)
        ptr1 = list1;
        ptr2 = list2;
        ptr3 = merged_list;
        
        while ptr1 and ptr2:
            if ptr1.val <= ptr2.val:
                ptr3.next = ptr1
                ptr1 = ptr1.next
            else:
                ptr3.next = ptr2
                ptr2 = ptr2.next
                    
            ptr3 = ptr3.next
            
        if ptr1:
            ptr3.next = ptr1
        else:
            ptr3.next = ptr2
        
        return merged_list.next