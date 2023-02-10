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
    /* DFS */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        
        // `nodes` keep track of the all the node values  
        // along the path 
        vector<int> nodes;
        dfs(root, targetSum, nodes, paths);
        return paths;
    }
private:
    void dfs(TreeNode* root, int taretSum, 
             vector<int>& currPath, vector<vector<int>>& paths) {
        // No root-to-leaf path when the root is empty
        if (!root)
            return;
        
        taretSum -= root->val;
        currPath.emplace_back(root->val);
        
        // When reaching the leaf node, check whether
        // we found the target sum.
        if (!root->left && !root->right && taretSum == 0) {
            paths.emplace_back(currPath);
        }
        
        // Continue to backtrack with DFS
        dfs(root->left, taretSum, currPath, paths);
        dfs(root->right, taretSum, currPath, paths);
        
        // Unset the current state
        currPath.pop_back();
    }
};