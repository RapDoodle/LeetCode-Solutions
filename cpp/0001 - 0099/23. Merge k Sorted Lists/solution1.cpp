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
    /* Time complexity: O(n*k) */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int k = lists.size();
        while (true) {
            bool found = false;
            int minVal = 0, minIdx;

            // Find the minimum value each time
            for (int i = 0; i < k; i++) {
                if (lists[i] == nullptr)
                    continue;
                if (!found || lists[i]->val < minVal) {
                    found = true;
                    minVal = lists[i]->val;
                    minIdx = i;
                }
            }

            // When no value is found for the current iteration,
            // it is guaranteed that no value can be found in 
            // subsequent iterations (all lists are nullptr) 
            if (!found)
                break;
            
            curr->next = lists[minIdx];
            curr = curr->next;
            
            // Append the node with the minimum value to the linked list
            lists[minIdx] = lists[minIdx]->next;
        }
        return head->next;
    }
};