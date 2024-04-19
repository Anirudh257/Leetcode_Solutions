// Time complexity: O(nlogn), Space complexity: O(n), n = total number of elements across all lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int numVecs = lists.size();
        // ListNode* dummy = new ListNode(-1);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &list: lists) {
            ListNode* curr = list;

            while(curr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }

        // printPQ(pq);
        ListNode* mergedList = sortPQ(pq);


        return mergedList;
    }
private:
    void printPQ(priority_queue<int>& pq) {
        while(!pq.empty()) {
            cout << pq.top() << endl;
            pq.pop();
        }
        return;
    }

    ListNode* sortPQ(priority_queue<int, vector<int>, greater<int>>& pq) {
        vector<int> revList;
        while(!pq.empty()) {
            revList.push_back(pq.top());
            pq.pop();
        }
        // reverse(revList.begin(), revList.end());

        ListNode* mergedList = new ListNode(-1);
        ListNode* curr = mergedList;

        for (auto &x : revList) {
            ListNode* newNode = new ListNode(x);
            curr->next = newNode;
            curr = curr->next;
        } 

        return mergedList->next;
    }
};
