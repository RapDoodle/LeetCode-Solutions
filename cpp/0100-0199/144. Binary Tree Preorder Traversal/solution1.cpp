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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        // Traverse without recursion
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* curr = s.top();
            ans.push_back(curr->val);
            s.pop();
            // Push curr->right first so that curr->left 
            // can be traversed first
            if (curr->right)
                s.push(curr->right);
            if (curr->left)
                s.push(curr->left);
        }
        return ans;
    }
};