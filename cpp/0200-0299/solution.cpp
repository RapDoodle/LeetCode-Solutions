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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, string s, vector<string>& ans) {
        if (root == nullptr)
            return;
        
        // Append root.val to string
        s += to_string(root->val);
        
        // When reached the leaf node, append and return
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(s);
            return;
        }
        
        // Not a leaf node, divide the string s into two
        s += "->";
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
    }
};