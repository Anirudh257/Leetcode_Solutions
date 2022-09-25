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
    void reorderList(ListNode* head) {
        if (!head->next) {
            return;
        }
        // Time complexity: O(n^2), Space complexity: O(1)
        ListNode* curr = head;
        ListNode* nextNode = head->next;
   
        // ListNode* revNode = revList(nextNode);
        
        // while(revNode) {
        //     cout << revNode->val << endl;
        //     revNode = revNode->next;
        // }
        
        
        while(curr) {
            // cout << curr->val << endl;
            // curr->next = NULL;
            ListNode* revNode = revList(nextNode);
            // cout << revNode->val << endl;
            curr->next = revNode;
            curr = curr->next;
            if (curr) {
                nextNode = curr->next;
            }
            // nextNode = curr->next;
        }
        
        return;
    }
private:
    ListNode* revList(ListNode* head) {
        ListNode* prev = NULL;
        
        ListNode* curr = head;
        
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // cout << prev->val << endl;
        return prev;
    }
};