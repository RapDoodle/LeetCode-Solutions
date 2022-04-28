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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while (head) {
            // Step 1: Register the next node
            next = head->next;
            
            // Step 2: Modify the reference to the next to  
            // the current node.
            head->next = prev;
            
            // Step 3: Register the previous node with the 
            // current node
            prev = head;
            
            // Step 4: Move on to the next node
            head = next;
        }
        return prev;
    }
};