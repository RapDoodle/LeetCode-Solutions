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
    /* BFS */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        
        // No root-to-leaf path when the root is empty
        if (!root)
            return paths;
        
        // Use a hash map to store the tree node's 
        // reverse link (their parents)
        unordered_map<TreeNode*, TreeNode*> revLink;
        
        // Use BFS
        queue<TreeNode*> path;
        queue<int> sums;
        path.push(root);
        sums.push(0);
        while (!path.empty()) {
            TreeNode* currNode = path.front();
            // Calculate the new sum
            int sum = currNode->val + sums.front();
            // When reaching the leaf node, check 
            // whether we found the target sum.
            if (!currNode->left && !currNode->right && 
                sum == targetSum) {
                // Found the target sum. Then trace the 
                // reverse link using the hash map
                paths.emplace_back(traceTreeNodes(currNode, revLink));
            } else {
                // Check along the left subtree
                if (currNode->left) {
                    path.push(currNode->left);
                    sums.push(sum);
                    revLink[currNode->left] = currNode;
                }
                // Check along the right subtree
                if (currNode->right) {
                    path.push(currNode->right);
                    sums.push(sum);
                    revLink[currNode->right] = currNode;
                }
            }
            path.pop();
            sums.pop();
        }
        return paths;
    }
private:
    vector<int> traceTreeNodes(TreeNode* leaf, 
                               unordered_map<TreeNode*, TreeNode*>& revLink) {
        vector<int> path;
        while (leaf) {
            path.emplace_back(leaf->val);
            leaf = revLink[leaf];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};