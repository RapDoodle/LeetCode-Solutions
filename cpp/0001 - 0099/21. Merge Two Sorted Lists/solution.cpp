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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (list1 != nullptr || list2 != nullptr) {
            // If list1 is empty, the remaining items are in list2
            if (list1 == nullptr) {
                curr->next = list2;
                break;
            }
            
            // If list2 is empty, the remaining items are in list1
            if (list2 == nullptr) {
                curr->next = list1;
                break;
            }
            
            // When both list1 and list2 are not empty
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            
            // Move the pointer to the current node
            curr = curr->next;
        }
        
        // The first node is the dummy node. This avoids explicit check
        // for every iteration
        return head->next;
    }
};