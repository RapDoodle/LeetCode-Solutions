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
    /* Stack */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Edge case: empty root
        if (!root)
            return {};
        
        int level = 0;
        stack<TreeNode*> stk1, stk2;
        stk1.emplace(root);
        vector<vector<int>> order;
        TreeNode* curr = nullptr;
        while (!stk1.empty()) {
            int levelSize = stk1.size();
            vector<int> levelOrder;
            while (levelSize-- > 0) {
                curr = stk1.top();
                stk1.pop();
                if (level % 2 == 0) {
                    // Push from left to right so that elements
                    // will be popped from right to left
                    if (curr->left)
                        stk2.emplace(curr->left);
                    if (curr->right)
                        stk2.emplace(curr->right);
                } else {
                    // Push from right to left so that elements
                    // will be popped from left to right
                    if (curr->right)
                        stk2.emplace(curr->right);
                    if (curr->left)
                        stk2.emplace(curr->left);
                }
                levelOrder.emplace_back(curr->val);
            }
            order.emplace_back(levelOrder);
            swap(stk1, stk2);
            ++level;
        }

        return order;
    }
};