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
    /* Priority Queue */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // Push the head of each linked list into the priority queue
        for (ListNode* list : lists) {
            if (list)
                pq.push(list);
        }
        
        // While the priority queue is not empty, look at 
        // the front of each (remaining) linked list:
        //  1. Add the minimum value to the new linked list
        //  2. Pop the minimum value
        //  3. Push the popped value's next entry (if any)
        //     to the priority queue
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next) {
                pq.push(curr->next);
            }
        }
        
        return dummy.next;
    }
};