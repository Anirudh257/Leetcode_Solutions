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

// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = k;
        while(cnt-- != 1 && temp) {
            temp = temp->next;
        }

        ListNode* startNode = temp;

        ListNode* fast = startNode;

        ListNode* slow = head;
        while(slow && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

    
        int stVal = startNode->val;
        int endVal = slow->val;

        startNode->val = endVal;
        slow->val = stVal;

        return head;
    }
};