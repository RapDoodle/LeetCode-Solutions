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
    void deleteNode(ListNode* node) {
        // Move the content of the next node to the current node
        node->val = node->next->val;

        // Register the next node
        ListNode* nextNode = node->next;

        // Skip the next node in the linked list
        node->next = nextNode->next;

        // Delete the next node (before modifying `next`)
        delete nextNode;
    }
};