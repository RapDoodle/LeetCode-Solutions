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
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* node = newHead;
        
        while (node != nullptr) {
            ListNode* l1 = node->next;
            
            // Check for end of the linked list
            if (l1 == nullptr)
                break;
            
            // Link: node --> l2 --> l1 --> l3
            ListNode* l2 = l1->next;
            if (l2 != nullptr) {
                // Register l2->next since l2 will be modified
                ListNode* l3 = l2->next;
                
                // Link nodes
                node->next = l2;
                l2->next = l1;
                l1->next = l3;
                
                // Move on to the node whose next node is unprocessed
                node = l1;
            } else {
                // If l2 is nullptr, meaning no pair to swap with l1
                break;
            }
        }
        return newHead->next;
    }
};