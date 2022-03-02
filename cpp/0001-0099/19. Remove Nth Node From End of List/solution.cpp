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
    /* The two-pointers approach */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        
        // i: the first pointer
        // j: the second pointer
        ListNode *iNode = &dummy, *jNode = head;
        
        // Create a distance of n from the dummy node (iNode)
        for (int i = 0; i < n; ++i)
            jNode = jNode->next;
        
        // Move iNode and jNode simultaneously until reaching the 
        // end of the list
        while (jNode != nullptr) {
            iNode = iNode->next;
            jNode = jNode->next;
        }
        
        // Already reached the end of the linked list
        // Remove the iNode->next
        ListNode* temp = iNode->next;
        iNode->next = iNode->next->next;
        delete temp;
        
        return dummy.next;
    }
};