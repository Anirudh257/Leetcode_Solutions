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
 // Time complexity: O(len(linked list)), Space complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Take n steps
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (!fast) {
            ListNode* tempNode = head->next;
            delete head;
            return tempNode;
        }

       // Reach the node before the node that needs to be deleted.
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        return head;
    }
};
