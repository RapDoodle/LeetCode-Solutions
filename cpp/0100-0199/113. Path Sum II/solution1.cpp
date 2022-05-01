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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        
        // `nodes` keep track of the all the node values  
        // along the path 
        vector<int> nodes;
        dfs(root, targetSum, 0, nodes, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, const int& tarSum, int currSum, 
             vector<int> nodes, vector<vector<int>>& ans) {
        // No root-to-leaf path when the root is empty
        if (!root)
            return;
        
        int sum = currSum + root->val;
        nodes.emplace_back(root->val);
        
        // When reaching the leaf node, check whether
        // we found the target sum.
        if (!root->left && !root->right && sum == tarSum) {
            ans.emplace_back(nodes);
            return;
        }
        
        // Continue to backtrack with DFS
        dfs(root->left, tarSum, sum, nodes, ans);
        dfs(root->right, tarSum, sum, nodes, ans);
        
        // Unset the current state
        nodes.pop_back();
    }
};