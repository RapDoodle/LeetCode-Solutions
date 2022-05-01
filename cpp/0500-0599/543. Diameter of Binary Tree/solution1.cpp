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
    int diameterOfBinaryTree(TreeNode* root) {
        // Return the maximum of the three:
        //  1. The length of the longest path that passes through
        //     the current node
        //  2. The length of the longest path that passes through
        //     the left node
        //  3. The length of the longest path that passes through
        //     the right node
        return root ? max(getHeight(root->left) + getHeight(root->right),
                          max(diameterOfBinaryTree(root->left), 
                              diameterOfBinaryTree(root->right))) : 0;
    }
private:
    int getHeight(TreeNode* root) {
        return root ? max(getHeight(root->left), 
                          getHeight(root->right)) + 1 : 0;
    }
};