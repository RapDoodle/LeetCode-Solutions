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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) 
            return nullptr;
        
        // Case 1: The current node's value is too small,
        // remove everything in the left-subtree
        if (root->val < low)
            return trimBST(root->right, low, high);
        
        // Case 2: The current node's value is too high, 
        // remove everything in the right-subtree
        if (root->val > high)
            return trimBST(root->left, low, high);
        
        // Case 3: The current node's value is within the 
        // valid range
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};