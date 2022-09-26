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
        if (!head || !head->next) {
            return;
        }   
        
        // Time complexity: O(N), Space complexity: O(N)
        stack<ListNode*> st;
        ListNode* curr = head;
        int size = 0;
        
        while(curr) {
            st.push(curr);
            size++;
            
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < size/2; i++) {
            ListNode* top = st.top();
            st.pop();
            
            top->next = curr->next;
            curr->next = top;
            curr = curr->next->next;
            
        }
        curr->next = NULL;
        
    }
};
