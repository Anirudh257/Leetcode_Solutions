// Time complexity: O(nlogn), Space complexity: O(nlogn),  n = total_elems in all lists
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
        ListNode* merged_list = new ListNode(-1);
        ListNode* ptr = merged_list;
        priority_queue<int> pq;
        
        for (auto &vec : lists) {
            ListNode* curr = vec;
            
            while(curr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        
        vector<int> sortedElems = sortPQ(pq);
                
        for (auto &x: sortedElems) {
            ListNode* newNode = new ListNode(x);
            ptr->next = newNode;
            ptr = ptr->next;
        }
        
        return merged_list->next;
    }
private:
    void printPQ(priority_queue<int>& pq) {
        while(!pq.empty()) {
            cout << pq.top() << endl;
            pq.pop();
        }
        return;
    }
    
    vector<int> sortPQ(priority_queue<int>& pq) {
        int size = pq.size();
        vector<int> sortedElems(size, -1);
        int i = size - 1;
            
        while(!pq.empty()) {
            sortedElems[i] = pq.top();
            pq.pop();
            i--;
        }
        
        return sortedElems;
    }
    
};