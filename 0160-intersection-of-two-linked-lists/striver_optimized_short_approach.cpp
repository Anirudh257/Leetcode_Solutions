// Time complexity: O(M + N), Space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Cover the lists twice so that both the head pointers are directly aligned.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;

        while (currA != currB) {
            currA = currA == NULL ? headB : currA->next;
            currB = currB == NULL ? headA : currB->next;
        }

        return currA;
    }
};