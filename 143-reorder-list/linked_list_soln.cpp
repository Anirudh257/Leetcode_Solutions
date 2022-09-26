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
    // Time complexity: O(N), Space complexity: O(1)
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Find the mid-point of the list
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* revHead = revList(slow);
        
        // cout << revHead->val << endl;
        ListNode* mergedList = mergeList(head, revHead);
        
        // while(mergedList) {
        //     cout << mergedList->val << endl;
        //     mergedList = mergedList->next;
        // }
        
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
        return prev;
    }
    
    ListNode* mergeList(ListNode* first, ListNode* second) {
        
        while(second && first) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
            
        }        
        return first;
    }
    
};
