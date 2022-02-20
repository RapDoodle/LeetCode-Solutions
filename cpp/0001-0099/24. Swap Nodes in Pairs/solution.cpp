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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(0, head);
        ListNode* curr = &dummy;
        
        // Link: curr --> l1 --> l2 --> l3
        ListNode *l1, *l2, *l3;
        while (curr != nullptr && 
               (l1 = curr->next) != nullptr && 
               (l2 = l1->next) != nullptr) {
            l3 = l2->next;
            
            // Link: curr --> l2 --> l1 --> l3
            curr->next = l2;
            l2->next = l1;
            l1->next = l3;

            // Move on to the node whose next node is unprocessed
            curr = l1;
        }
        return dummy.next;
    }
};