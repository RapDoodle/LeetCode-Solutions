/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /* O(1) space complexity */
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        
        // For each node, create a duplicate node
        // between the current node and the original
        // linked list's next node
        //  1 -> 2 -> 3
        //  1 -> 1 -> 2 -> 2 -> 3 -> 3
        Node *curr = head, *next = nullptr, *newNode;
        while (curr) {
            next = curr->next;
            newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = next;
            curr = curr->next->next;
        }

        // Link the new node's random pointer by
        // referencing the original linked list
        curr = head;
        while (curr) {
            // curr->random could be pointing to
            // a null pointer
            if (curr->random)
                curr->next->random = curr->random->next;
            // Move on to the next node that belongs to
            // the original linked list
            curr = curr->next->next;
        }

        // Separate the two linked lists and restore the
        // the original linked list's pointer references
        curr = head;
        Node *newHead = curr->next, *nextOld = nullptr;
        while (curr && curr->next && curr->next->next) {
            nextOld = curr->next->next;
            curr->next->next = nextOld->next;
            curr->next = nextOld;
            curr = curr->next;
        }
        // The last node in the original linked list
        curr->next = nullptr;

        return newHead;
    }
};