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
        // Use BFS
        if (!root)
            return nullptr;
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode *curr = nullptr, *temp = nullptr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            swap(curr->left, curr->right);
            if (curr->left)
                q.emplace(curr->left);
            if (curr->right)
                q.emplace(curr->right);
        }
        return root;
    }
};