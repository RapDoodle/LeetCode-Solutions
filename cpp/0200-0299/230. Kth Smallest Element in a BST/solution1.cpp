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
    /* Inorder traversal */
    int kthSmallest(TreeNode* root, int k) {
        // The k-th element in inorder traversal
        // gives the k-th smallest node in a BST.
        // Simulate inorder traversal with a stack.
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            while (root) {
                if (root->left)
                    stk.emplace(root->left);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (k == 1)
                return root->val;
            --k;
            if (root->right)
                stk.emplace(root->right);
            root = root->right;
        }
        // Not found
        return -1;
    }
};