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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        // Time complexity: O(N), Space complexity: O(1)
        // cout << " Here" << endl;
        
        ListNode* slow = head; 
        ListNode* fast = head->next;
        
        // cout << slow->val << " " << fast->val << endl;
        // cout << !slow << " " << !fast << endl;
        while(slow && fast) {
            slow = slow->next;
            // cout << " here" << endl;
            if (fast->next) {
                fast = fast->next->next;
            }
            else {
                return false;
            }
            
            // cout << slow->val << " " << fast->val << endl;
            
            if (slow == fast) {
                return true;
            }
            
        }
        return false;
    }
};