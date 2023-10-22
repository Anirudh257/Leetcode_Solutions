// Time complexity: O(N), Space complexity: O(N)
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode* > uniqNodes;
        ListNode* curr = head;
        while(curr != NULL) {
            if (uniqNodes.count(curr) != 0) {
                return curr;
            }
            uniqNodes.insert(curr);
            curr = curr->next;
        }

        return NULL; 
    }
};