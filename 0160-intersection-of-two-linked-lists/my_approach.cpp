// Time complexity: O(M + N), Space complexity: O(M), M = len(listA), N = len(listB)

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
        unordered_set<ListNode*> node_set;
        ListNode* currA = headA;
        ListNode* currB = headB;

        while(currA != NULL) {
            node_set.insert(currA);
            currA = currA->next;
        }

        while(currB != NULL) {
            if (node_set.count(currB)) {
                return currB;
            }
            currB = currB->next;
        }

        return NULL;
    }
};