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
        return abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
                isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* root) {
        // Base case: reaching nullptr
        // Recursive case: return the maximum of the two paths, 
        // then plus the height of the current level
        return root ? max(getHeight(root->left), getHeight(root->right)) + 1 : 0;
    }
};