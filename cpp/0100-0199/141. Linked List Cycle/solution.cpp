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
    bool hasCycle(ListNode *head) {
        // Edge case: empty linked list
        if (!head)
            return false;
        
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            // Move the slow pointer one step at a time
            slow = slow->next;
            
            // Move the fast pointer two steps at a time
            fast = fast->next->next;
            
            // Detect whether the fast pointer runs into 
            // the slow pointer, indicating a loop
            if (fast == slow)
                return true;
        }
        
        // The linked list contains null, indicating not a 
        // cycle
        return false;
    }
};