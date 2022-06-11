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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            // At this point, root is a nullptr
            root = stk.top();
            if (!root->right || root->right == prev) {
                ans.emplace_back(root->val);
                // Set prev to the current node to avoid
                // stucking in an infinite loop when 
                // traversing back up.
                prev = root;
                // Hint the algorithm to directly go back
                // up 1 step
                root = nullptr;
                stk.pop();
            } else {
                // The current root has a right-subtree
                root = root->right;
            }
        }
        return ans;
    }
};