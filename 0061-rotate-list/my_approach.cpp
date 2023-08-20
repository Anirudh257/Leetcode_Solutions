// Time complexity: O(N), Space complexity: O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head || !head->next) {
            return head;
        }    

        ListNode* newHead = rotateK(head, k);

        return newHead;
    }
private:
    int compLen(ListNode* head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* getOrigLastNode(ListNode* head) {
        ListNode* curr = head;

        while(curr->next != NULL) {
            curr = curr->next;
        }
        return curr;
    }

    ListNode* rotateK(ListNode* head, int k) {
        int lenList = compLen(head);
        ListNode* lastNode = getOrigLastNode(head);
        k = k % lenList;

        if (k == 0) {
            return head;
        }

        int c = 1;
        ListNode* curr = head;
        while(c < lenList - k) {
            curr = curr->next;
            c++;
        }
        ListNode* temp = curr->next;
        curr->next = NULL;
        lastNode->next = head;

        return temp;
    }
};