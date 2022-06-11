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
        
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            // When root->val == key
            // Case 1: If the node to be deleted is a leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            
            // Case 2: If the node to be deleted has two children,
            // then find the minimum in the right-subtree (the 
            // inorder predecessor)
            if (root->left && root->right) {
                TreeNode* successor = findMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
                return root;
            }
            
            // Case 3: If the node to be deleted has only one child
            TreeNode* temp = nullptr;
            if (root->left)
                temp = root->left;
            else
                // root->right
                temp = root->right;
            
            delete root;
            return temp;
            
        }
        return root;
    }
    
    TreeNode* findMin(TreeNode* root) {
        if (!root || !root->left)
            return root;
        return findMin(root->left);
    }
};