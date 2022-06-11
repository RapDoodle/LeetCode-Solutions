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
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool isValidBST(TreeNode* root, long rangeMin, long rangeMax) {
        if (!root)
            return true;
        if (root->val <= rangeMin || root->val >= rangeMax)
            return false;
        return isValidBST(root->left, rangeMin, root->val) && 
               isValidBST(root->right, root->val, rangeMax);
    }
};