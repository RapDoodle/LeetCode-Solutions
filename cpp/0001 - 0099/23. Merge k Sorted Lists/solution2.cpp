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
    /* Time complexity O(n*logk) */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Merge two sorted linked list
        ListNode* head = new ListNode();
        ListNode* curr = head;
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                curr->next = l2;
                break;
            }
            
            if (l2 == nullptr) {
                curr->next = l1;
                break;
            }
            
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            
            curr = curr->next;
        }
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        if (k == 0)
            return nullptr;
        
        /* Iteratively merge every two linked lists, so that only
           log(k) times of operations are executed, instead of k.
           For a linked lists 1, 2, 3, 4, 5
           First iteration: merge 1 and 2, 3 and 4, 5 and nullptr 
             (merge with itself). We get (1, 2), (3, 4), and (5)
           Second iteration: (1, 2, 3, 4), and (5)
           Third iteration: (1, 2, 3, 4, 5)
           NOTE: one more iteration is needed when the number of
                 linked lists is 
                 (1) odd OR 
                 (2) an itermediate step results in odd number 
                     of linked lists
        */
        int step = 2, bound = (k % 2 == 0 && k % 3 != 0 && k % 5 != 0) ? 
            (k + (k % 2)) : (k + (k % 2)) * 2;
        while (step <= bound) {
            for (int i = 0; i < k; i += step) {
                ListNode* l1 = lists[i];
                // Determine whether l2 will cause out-of-bound error.
                // If so, assign it the nullptr
                int l2Idx = i + (step / 2);
                ListNode* l2 = l2Idx < k ? lists[l2Idx] : nullptr;
                
                // The merged linked list is stored at the i-th position
                lists[i] = (l2 != nullptr) ? 
                    mergeTwoLists(l1, l2) : l1;
            }
            step *= 2;
        }
        
        return lists[0];
    }
};