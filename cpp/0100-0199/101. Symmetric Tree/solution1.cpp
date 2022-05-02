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
    /* Use DFS */
    bool isSymmetric(TreeNode* root) {
        return root ? checkSymmetric(root, root) : true;
    }
    
private:
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        // Reaching the end at both sides
        if (!left && !right)
            return true;
        
        // Check whether one of the nodes does not exist
        if (!left || !right)
            return false;
        
        // Check whether they have different values
        if (left->val != right->val)
            return false;
        
        // Recursively check the symmetry
        return checkSymmetric(left->left, right->right) &&
            checkSymmetric(left->right, right->left);
    }
};