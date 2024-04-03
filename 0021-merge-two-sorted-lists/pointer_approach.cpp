// Time complexity: O(n1 + n2), n1 = len(list1), n2 = len(list2), Space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList = new ListNode(-1000);
        
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* ptr3 = mergedList;
        
        while(ptr1 && ptr2) {
            int val1 = ptr1->val;
            int val2 = ptr2->val;
            
            if (val1 <= val2) {
                ptr3->next = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                ptr3->next = ptr2;
                ptr2 = ptr2->next;                
            }
            ptr3 = ptr3->next;
        }
        
        if (ptr1) {
            ptr3->next = ptr1;
        }
        else {
            ptr3->next = ptr2;
        }
        return mergedList->next;
    }
};