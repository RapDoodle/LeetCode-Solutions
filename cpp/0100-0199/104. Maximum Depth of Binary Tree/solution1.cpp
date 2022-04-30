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
    int maxDepth(TreeNode* root) {
        // Base case: reaching nullptr
        if (!root)
            return 0;
        
        // Recursive case: return the maximum of the two paths, 
        // then plus one (the height of the current level)
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};