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
        
        return abs(getHeight(root->left)-getHeight(root->right)) <= 1 && 
                isBalanced(root->left) && 
                isBalanced(root->right) ? true : false;
    }
private:
    int getHeight(TreeNode* root) {
        // Return the height of the tree / subtree
        return root ? max(getHeight(root->left), 
                          getHeight(root->right)) + 1 : 0;
    }
};