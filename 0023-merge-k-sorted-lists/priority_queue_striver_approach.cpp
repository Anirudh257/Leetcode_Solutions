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

 // Time complexity: 1st for loop: KlogK + NKlogK for 2nd while loop, Space complexity: O(K)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min-heap ordered by least element
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        int numLists = lists.size();

        for (int i = 0; i < numLists; i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* mergedList = new ListNode(0);
        ListNode* dummy = mergedList;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            dummy->next = top.second;

            if (top.second->next) {
                pq.push({top.second->next->val, top.second->next});
            }

            dummy = dummy->next;
        }

        return mergedList->next;
    }
};
