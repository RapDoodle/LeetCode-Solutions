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
    ListNode *detectCycle(ListNode *head) {
        // Edge case: empty linked list
        if (!head)
            return nullptr;
        
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            // Move the slow pointer one step at a time
            slow = slow->next;
            
            // Move the fast pointer two steps at a time
            fast = fast->next->next;
            
            // Detect whether the fast pointer runs into 
            // the slow pointer, indicating a loop
            if (fast == slow) {
                // Reset the fast to the beginning of the 
                // list
                fast = head;
                while (fast != slow) {
                    // Move the fast and slow pointer one 
                    // step at a time, until the two meets
                    slow = slow->next;
                    fast = fast->next;
                }
                
                // When the fast and slow pointer meet for 
                // the second time, the node is the node in 
                // which the loop starts
                return fast;
            }
        }
        
        // The linked list contains null, indicating no 
        // cycle exists
        return nullptr;
    }
};