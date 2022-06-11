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
    TreeNode* invertTree(TreeNode* root) {
        // Use recursion
        if (!root)
            return nullptr;
        
        // Recursively invert the subtree
        TreeNode* invertedLeft = invertTree(root->left);
        TreeNode* invertedRight = invertTree(root->right);
        root->left = invertedRight;
        root->right = invertedLeft;
        
        return root;
    }
};