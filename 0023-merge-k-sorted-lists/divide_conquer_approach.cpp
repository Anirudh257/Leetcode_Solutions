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
 // Time complexity: O(nlogk), n = number of nodes, k = number of lists, Space complexity: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int numLists = lists.size();
        int itvlSize = 1;
 
        while(itvlSize < numLists) {
            for (int i = 0; i < numLists - itvlSize; i += itvlSize*2) {
                lists[i] = merge2Lists(lists[i], lists[i + itvlSize]);
            }
            itvlSize *= 2;
        }
        return numLists > 0 ? lists[0] : NULL;
    }
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = new ListNode(0);
        ListNode* curr = mergedList;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        }
        else {
            curr->next = l2;
        }
        return mergedList->next;
    }
};
