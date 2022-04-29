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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Use two pointers, move them at the same speed. When reaching
        // the end of the linked list, set the pointer to the beginning
        // of the other linked list. After O(m + n) steps, they are 
        // guaranteed to start from equal distance to the end of the 
        // linked list. Now, we can simply move one step forward at a 
        // time and see whether the two nodes' reference euqal to 
        // each other.
        // If no intersection is found, they will terminate when both
        // nodes are nullptr.
        ListNode *l1 = headA, *l2 = headB;
        while (l1 != l2) {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        
        // l1 and l2 are both equivalent
        return l1;
    }
};