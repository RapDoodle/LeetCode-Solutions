/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        
        // Locate the position to delete
        TreeNode *curr = root, *parent = nullptr;
        while (curr && curr->val != key) {
            parent = curr;
            if (curr->val > key)
                curr = curr->left;
            else
                // curr->val < key
                curr = curr->right;
        }
        
        // Return if the given key does not exists in the BST
        if (!curr) 
            return root;
        
        // When curr->val == key
        // Register the node to be deleted
        TreeNode* temp = curr;
        if (!curr->left && !curr->right) {
            // Case 1: If the node to be deleted is a leaf node
            curr = nullptr;
        } else if (!curr->left) {
            // Case 2-1: If the node to be deleted has only the
            // right-child
            curr = curr->right;
        } else if (!curr->right) {
            // Case 2-2: If the node to be deleted has only the
            // left-child
            curr = curr->left;
        } else {
            // When curr->left && curr->right
            // Case 3: If the node to be deleted has two children,
            // find the minimum in the right-subtree (the inorder
            // predecessor)
            TreeNode *successor = curr->right, *successorParent = curr;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }
            
            // If the successor's parent is the current node, the 
            // inorder predecessor should be linked to the right of 
            // the current node. E.g.,
            //      1                  3
            //     / \    delete 1    / \
            //    2   3   -------->  2   4
            //         \
            //          4
            // In this example, 3 is the successor, the successor's
            // parent is 1.
            // Otherwise, it belongs to the left path
            //      1                  3
            //     / \                / \
            //    2   5   delete 1   2   5
            //       / \  -------->     / \
            //      3   6              4   6
            //       \
            //        4
            // In this example, 3 is the successor, the successor's
            // parent is 5.
            if (successorParent == curr)
                successorParent->right = successor->right;
            else
                successorParent->left = successor->right;
            
            // Move the successor to curr's position
            successor->right = curr->right;
            successor->left = curr->left;
            curr = successor;
        }
        
        if (!parent) {
            // When the node (to be) deleted is the root node
            delete temp;
            return curr;
        } else if (parent->left && parent->left->val == key) {
            // The node (to be) deleted belongs to the left-subtree
            // of its parent
            parent->left = curr;
        } else {
            // The node (to be) deleted belongs to the right-subtree
            // of its parent
            parent->right = curr;
        }
        
        delete temp;
        return root;
    }
};