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
// Time complexity: O(2*N), Space complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        int cnt = 0;

        if (!head->next) {
            return NULL;
        }

        while(first->next != NULL && second->next != NULL) {
            second = second->next;
            cnt += 1;
            if (cnt == n) {
                first = first->next;
                cnt = 0;
            }
        }
        if (first) {
            cout << first->val << endl;
        }

        // if (!first) {
        //     return NULL;
        // }

        // if (first == second) {

        // }

        ListNode* nextNode = first->next;
        ListNode* remNodes = NULL;
        if (nextNode) {
            remNodes = nextNode->next;
        }
        first->next = remNodes;

        return head;
    }
};