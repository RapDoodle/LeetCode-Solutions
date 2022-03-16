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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Reached the leaf nodes
        if (p == nullptr && q == nullptr)
            return true;
        
        // When the two nodes are not empty and 
        // have the same value, search using DFS in
        // the left and right path recursively.
        if (p != nullptr && q != nullptr && p->val == q->val)
            return isSameTree(p->left, q->left) && 
                   isSameTree(p->right, q->right);
        
        // When the two nodes' values are different,
        // or at least one node is a null pointer, 
        // which indicates the two paths are different.
        return false;
    }
};