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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return getHeight(root) >= 0;
    }
private:
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        
        // Use -1 to denote an unbalanced tree / subtree is found
        int leftH = getHeight(root->left);
        if (leftH == -1)
            return -1;
        
        int rightH = getHeight(root->right);
        if (rightH == -1)
            return -1;
        
        // Check if the tree / subtree is unbalanced
        if (abs(leftH - rightH) > 1)
            return -1;
        
        // Otherwise, simply return the height
        return max(leftH, rightH) + 1;
    }
};