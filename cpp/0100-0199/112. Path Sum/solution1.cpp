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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // No root-to-leaf path when the root is empty
        if (!root)
            return false;
        
        // Calculate the new sum
        targetSum -= root->val;
        
        // When reaching the leaf node, check whether
        // we found the target sum.
        if (!root->left && !root->right && targetSum == 0)
            return true;
        
        // If either path returns true, then there 
        // exists at least one root-to-leaf path
        return hasPathSum(root->left, targetSum) ||
            hasPathSum(root->right, targetSum);
    }
};