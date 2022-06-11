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
    bool isValidBST(TreeNode* root) {
        // Use inorder traversal. Detailed explanation
        // on inorder traversal without recursion can
        // be found in the solution for problem 94
        stack<TreeNode*> stk;
        long currMin = LONG_MIN;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            
            // The result of inorder traversal of a  
            // BST must be strictly increasing
            if (root->val <= currMin) return false;
            currMin = root->val;
            
            stk.pop();
            root = root->right;
        }
        return true;
    }
};