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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        // Container for answers
        vector<TreeNode*> ans;
        
        // A map to determine whether or not delete is needed in O(1)
        unordered_set<int> map(toDelete.begin(), toDelete.end());
        
        // DFS
        root = helper(root, map, ans);
        
        // If root was not deleted, add it to the list of answeres
        if (root)
            ans.emplace_back(root);
        
        return ans;
    }
    
private:
    TreeNode* helper(TreeNode* root, unordered_set<int>& map, vector<TreeNode*>& ans) {
        if (!root)
            return root;
        
        // If the child was deleted, set the reference to null (according to the 
        // helper function's return value)
        root->left = helper(root->left, map, ans);
        root->right = helper(root->right, map, ans);
        
        if (map.find(root->val) != map.end()) {
            // When the current node should be deleted
            if (root->left)
                ans.emplace_back(root->left);
            if (root->right)
                ans.emplace_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
};