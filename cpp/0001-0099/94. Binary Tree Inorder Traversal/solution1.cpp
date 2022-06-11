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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        // Simulate the internal stack
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            // Push until reaching current root's left-most node
            while (root) {
                stk.push(root);
                root = root->left;
            }
            
            // At this point, root is a nullptr.
            // Handle the current value as it has no nodes to the 
            // left that are not visited yet.
            root = stk.top();
            stk.pop();
            ans.emplace_back(root->val);
            
            // Visit the right-subtree. 
            // If the current node does not have a right-subtree,
            // the loop in line 21-24:
            //      while (root) { ... }
            // will not be executed. Instead, the algorithm will 
            // directly fetch a node from the top of the stack.
            root = root->right;
        }
        
        return ans;
    }
};