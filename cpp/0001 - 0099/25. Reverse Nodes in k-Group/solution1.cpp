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
    /* Time complexity: O(n), space complexity: O(n) */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode* node = &dummy;
        ListNode* checkPoint = nullptr;
        stack<ListNode*> s;
        
        while (head != nullptr || s.size() == k) {
            if (s.size() < k) {
                // Create a checkpoint for trailing nodes that
                // do not need to be reversed
                if (s.size() == 0)
                    checkPoint = head;
                
                // Add nodes to the stack until a group is formed
                s.push(head);
                head = head->next;
            } else {
                // When s.size() == k:
                // Stack is full, pop all elements from stack
                // and add to the linked list
                while (s.size() > 0) {
                    node->next = s.top();
                    s.pop();
                    node = node->next;
                }
            }
        }
        
        if (s.size() > 0) {
            // All the remaining nodes in the linked list
            node->next = checkPoint;
        } else {
            // Finalize the linked list
            node->next = nullptr;
        }
        
        return dummy.next;
    }
};