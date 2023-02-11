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
    /* Hash map */
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;

        // Phase 1: Duplicate the nodes
        // (without links)
        Node* curr = head;
        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Phase 2: Create links
        curr = head;
        while (curr) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }

        return m[head];
    }
};