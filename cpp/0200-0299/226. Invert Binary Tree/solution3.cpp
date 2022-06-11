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
        // Use DFS (without recursion). Detailed explanation 
        // on the solution for problem 145
        stack<TreeNode*> stk;
        TreeNode *prev = nullptr, *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.emplace(curr);
                curr = curr->left;
            }
            curr = stk.top();
            if (!curr->right || curr->right == prev) {
                swap(curr->left, curr->right);
                prev = curr;
                curr = nullptr;
                stk.pop();
            } else {
                curr = curr->right;
            }
        }
        return root;
    }
};