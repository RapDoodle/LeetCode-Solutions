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
    /* The two(three)-pointers approach */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // i: the node before node j
        // j: the node to be deleted
        // k: the leading node (used to look for the last node)
        
        int j = -n;
        ListNode *iPtr = nullptr, *jPtr = head, *kPtr = head;
        while (kPtr != nullptr) {
            kPtr = kPtr->next;
            j++;
            
            // Only start moving when k - n is positive
            if (j > 0) {
                iPtr = jPtr;
                jPtr = jPtr->next;
            }
        }
        
        if (j == 0)
            return jPtr->next;  // Delete the first node
        else
            iPtr->next = jPtr->next;
        
        return head;
    }
};