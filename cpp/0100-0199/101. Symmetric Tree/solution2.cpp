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
    /* Use BFS */
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        vector<TreeNode*> curr;
        curr.emplace_back(root);
        while (!curr.empty()) {
            vector<TreeNode*> next;
            int n = curr.size() / 2;
            for (int i = 0; i < n; ++i) {
                cout << 1;
                TreeNode *left = curr[i], *right = curr[curr.size()-i-1];
                // Reaching the end at both sides
                if (!left && !right)
                    continue;
                
                // Check whether one of the nodes does not exist
                if (!left || !right)
                    return false;
                
                // Check whether they have different values
                if (left->val != right->val)
                    return false;
            }
            
            // Insert the nodes from the next level
            for (int i = 0; i < curr.size(); ++i) {
                if (!curr[i])
                    continue;
                next.push_back(curr[i]->left);
                next.push_back(curr[i]->right);
            }
            
            // Swap
            curr = next;
        }
        
        return true;
    }
};