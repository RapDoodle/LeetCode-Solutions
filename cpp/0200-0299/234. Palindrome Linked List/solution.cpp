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
    bool isPalindrome(ListNode* head) {
        // Use fast-moving-pointer and slow-moving pointer
        // to find the middle point of the linked list:
        //  fast-moving: move two steps at a time
        //  slow-moving: move one step at a time
        // After the loop, the slow-moving-pointer should 
        // point at the middle of the linked list (n is odd)
        // or the end of the first half (n is even).
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list.
        // Then compare the two halfs element by element.
        // Note: when n is odd, upon reaching the element 
        // in the middle, head2 == nullptr, which fails
        // the looping criteria.
        ListNode* head2 = reverseLinkedList(slow->next);
        while (head && head2) {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
private:
    // LeetCode problem 206
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while (head) {
            // Step 1: Register the next node
            next = head->next;
            
            // Step 2: Modify the reference to the next to  
            // the current node.
            head->next = prev;
            
            // Step 3: Register the previous node with the 
            // current node
            prev = head;
            
            // Step 4: Move on to the next node
            head = next;
        }
        return prev;
    }
};