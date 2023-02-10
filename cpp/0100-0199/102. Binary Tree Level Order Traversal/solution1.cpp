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
    /* BFS */
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Edge case: empty root
        if (!root)
            return {};
        
        // BFS
        vector<vector<int>> order;
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode* curr = nullptr;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelOrder;
            levelOrder.reserve(levelSize);
            while (levelSize-- > 0) {
                curr = q.front();
                q.pop();
                levelOrder.emplace_back(curr->val);
                if (curr->left)
                    q.emplace(curr->left);
                if (curr->right)
                    q.emplace(curr->right);
            }
            order.emplace_back(levelOrder);
        }
        
        return order;
    }
};