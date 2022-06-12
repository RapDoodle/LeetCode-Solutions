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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // NOTE: The algorithm merges root2 into root1. 
        // The structure of root1 will be changed.
        // Case 1: Two roots are empty, reached the end of the tree.
        if (!root1 && !root2)
            return nullptr;
        
        if (root1 && root2) {
            // Case 2: Both roots exist, merge the value of root2
            // into root1
            root1->val += root2->val;
        } else if (root2) {
            // Case 3-1: Only root2 exists, replace root1 with root2
            // and continue on root1
            root1 = root2;
            root2 = nullptr;
        }
        //  // (Case 3-2: Only root1 exists, continue on root1)
        
        root1->left = mergeTrees(root1->left, root2 ? root2->left : nullptr);
        root1->right = mergeTrees(root1->right, root2 ? root2->right : nullptr);
        
        return root1;
    }
};