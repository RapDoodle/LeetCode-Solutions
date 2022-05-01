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
        int length = 0;
        helper(root, length);
        return length;
    }
private:
    int helper(TreeNode* root, int& length) {
        if (!root)
            return 0;
        
        // The depth of the left tree/subtree
        int leftH = helper(root->left, length);
        
        // The depth of the right tree/subtree
        int rightH = helper(root->right, length);
        
        // The length of the longest path that  
        // passes through the current node
        length = max(length, leftH + rightH);
        
        // Return the depth starting from the 
        // current node
        return max(leftH, rightH) + 1;
    }
};