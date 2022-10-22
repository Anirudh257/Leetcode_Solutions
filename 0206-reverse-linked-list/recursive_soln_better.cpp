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
    ListNode* reverseList(ListNode* head) {
        // Time complexity: O(n), Space complexity: O(1) + Auxiliary Space: O(N)
        if (!head || !head->next) {
            return head;
        }
        ListNode* revSubList = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return revSubList;
    }
};
