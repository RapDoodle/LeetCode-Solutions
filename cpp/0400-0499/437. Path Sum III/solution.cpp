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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        
        // Divide the problem into two cases:
        //  1. The root is included in the sum
        //  2. The root is excluded from the sum
        int count = 0;
        count += rootSum(root, (long)targetSum);
        count += pathSum(root->left, targetSum) + 
                 pathSum(root->right, targetSum);
        return count;
    }

private:
    int rootSum(TreeNode* root, long targetSum) {
        if (!root)
            return 0;
        
        int count = 0;
        
        // The new target sum
        targetSum -= root->val;
        if (targetSum == 0)
            ++count;
        count += rootSum(root->left, targetSum);
        count += rootSum(root->right, targetSum);
        return count;
    }
};