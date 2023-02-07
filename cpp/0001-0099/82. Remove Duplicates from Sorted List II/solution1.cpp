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
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node
        ListNode* newHead = new ListNode(0, head);

        // Use two pointers. ptr2 is used to find duplicate nodes.
        ListNode *ptr1 = newHead, *ptr2 = head;
        while (ptr2) {
            if (ptr2->next && ptr2->val == ptr2->next->val) {
                // At least two duplicate nodes
                int currVal = ptr2->val;
                ListNode* nextNode;
                while (ptr2 && ptr2->val == currVal) {
                    // Delete the current node and move on to
                    // the next
                    nextNode = ptr2->next;
                    delete(ptr2);
                    ptr2 = nextNode;
                }
                // Relink
                ptr1->next = ptr2;
            } else {
                // Not a duplicate
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
        }

        // Delete the dummy node and return
        head = newHead->next;
        delete(newHead);
        return head;
    }
};