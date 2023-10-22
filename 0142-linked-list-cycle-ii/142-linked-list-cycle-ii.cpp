// Time complexity: O(N), Space complexity: O(1)
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
        if (!head || !head->next) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        // 1) Find the collision point between slow and fast pointers.

        // Fast pointer always travels more cycles than the slow pointer.

        // 2) Find the starting point.

        // If slow travels: L1 + L2 distance.

        // L1 = distance from start of linked list and L2 = distance from 
        // start of the cycle.

        // fast pointer travels: L1 + L2 + nC(C = length of the cycle)

        // At collision point, distance travelled by fast = 2*distance traversed by slow

        // 2*(L1 + L2) = L1 + L2 + nC

        // L1 = nC - L2

        // Starting from the start, the distance is L1.
        // So we can start from the start and make slow traverse 1 step at a time to find the relevant cycle starting point.

        while(fast) {
            if (slow->next) {
                slow = slow->next;
            }

            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            }
            else {
                fast = fast->next;
            }

            if (slow == fast) {
                break;
            }
        }

        if (fast == NULL) {
            return NULL;
        }

        ListNode* start = head;

        while(start != slow && slow && start) {
            start = start->next;
            slow = slow->next;
        }

        if (slow != NULL) {
            return slow;
        }

        return NULL; 
    }
};