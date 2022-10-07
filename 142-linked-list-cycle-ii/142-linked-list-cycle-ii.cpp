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
        
        
        // Time complexity: O(N), Space complexity: O(1)
        if (!head || !head->next) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                while(entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
            
        }
        
        return nullptr;
    }
};