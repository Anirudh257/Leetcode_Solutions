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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = compLen(headA);
        int lenB = compLen(headB);
        ListNode* currA = headA;
        ListNode* currB = headB;

        if (lenA > lenB) {
            int diffLen = lenA - lenB;
            while(diffLen-- != 0) {
                currA = currA->next;
            }
        }
        else {
            int diffLen = lenB - lenA;
            while(diffLen-- != 0) {
                currB = currB->next;
            }            
        }

        while(currA && currB) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        
        }

        return NULL;
    }
private:
    int compLen(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }

        return len;
    }
};