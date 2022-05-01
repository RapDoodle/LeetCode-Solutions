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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // No root-to-leaf path when the root is empty
        if (!root)
            return false;
        
        // Use BFS
        queue<TreeNode*> nodes;
        queue<int> sums;
        nodes.push(root);
        sums.push(0);
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size-- > 0) {
                TreeNode* currNode = nodes.front();
                
                // Calculate the new sum
                int sum = currNode->val + sums.front();
                
                // When reaching the leaf node, check 
                // whether we found the target sum.
                if (!currNode->left && !currNode->right && 
                    sum == targetSum)
                    return true;
                
                // Check along the left subtree
                if (currNode->left) {
                    nodes.push(currNode->left);
                    sums.push(sum);
                }
                
                // Check along the right subtree
                if (currNode->right) {
                    nodes.push(currNode->right);
                    sums.push(sum);
                }
                nodes.pop();
                sums.pop();
            }
        }
        
        return false;
    }
};