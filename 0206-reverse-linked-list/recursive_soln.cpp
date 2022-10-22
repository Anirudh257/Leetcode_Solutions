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
    // Time complexity: O(n), Space complexity: O(1) + Auxiliary Space O(n)
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        return getRevList(head, NULL);
    }
private:
    ListNode* getRevList(ListNode* head, ListNode* prev) {
        if (!head) {
            return prev;
        }
        
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        

        return getRevList(nextNode, prev);
    }
};
