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
    /* Time complexity: O(n), space complexity: O(1) */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Count the number of nodes in the linked list.
        // Then, by reducing the count after each iteration,
        // we can compare it with k. This helps us
        // determine whether or not we need to reverse the group.
        ListNode* node = head;
        int m = 0;
        while (node != nullptr) {
            node = node->next;
            m++;
        }
        
        // The new head of the linked list, a dummy node
        ListNode* newHead = new ListNode();
        
        // The first node in a group (will be the last node
        // after reversed)
        ListNode* gHead = nullptr;
        
        // The node right before gHead in the original order
        ListNode* gPrev = newHead;
        
        // For each step, link l2 to l1.
        // l3 is a register for l2->next since the value of 
        // l2->next will modified after linking to l1 
        ListNode *l1 = head, *l2 = nullptr, *l3 = nullptr;
        
        // Check for whether there are enough nodes to form
        // a group to be reversed
        while (m >= k) {
            gHead = head;
            l1 = head;
            l2 = head->next;
            // Avoid setting l3 here as l2 could be nullptr
            l3 = nullptr;  
            for (int i = 0; i < k - 1; i++) {
                // The for-loop will only execute when k >= 2,
                // this guarantees l2 is not nullptr. Then, only
                // in the first iteration for each group, set the
                // l3 to register l2->next
                if (l3 == nullptr)
                    l3 = l2->next;
                
                // Create the linkage l2->l1
                l2->next = l1;
                
                // Move l1, l2, and l3 without relying on l2->next
                // (l2->next has been changed to l1 already)
                l1 = l2;
                l2 = l3;
                
                // Edge case: l2 = l1->next is nullptr
                if (l3 != nullptr)
                    l3 = l3->next;
            }
            // NOTE: l1, l2, and l3 moved one more step, so when k = 3,
            // the linked ist becomes:
            // ... <-- (1 <-- 2 <-- 3) --> ... --> ...
            //                      ^       ^       ^
            //                      |       |       |
            //                      l1      l2      l3
            
            // Move the head (the original pointer passed in) to the 
            // last relinked node's next (l2)
            head = l2;
            
            // Connect the last node in the previous group to the head
            // of the current reversed group (the last relinked node).
            // In the example above, the 3 (l1)
            gPrev->next = l1;
            
            // The first node in the original order becomes the last node
            // when reversed. The last node of the current group is the 
            // "previous node" for the next group. Register the node
            // so that it can connect to the first node in the next  
            // reversed group (last node in the original order)
            gPrev = gHead;
            
            m -= k;
        }
        
        // If there are remaining nodes, simply connect the remaining 
        // linked list to last node in the previous group (or the dummy
        // head when m < k)
        if (m > 0)
            gPrev->next = head;
        else
            gPrev->next = nullptr;
        
        return newHead->next;
    }
};