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
        
        // No root-to-leaf path when the root is empty
        if (!root)
            return ans;
        
        // Use a hash map to store the tree node's 
        // reverse link (their parents)
        unordered_map<TreeNode*, TreeNode*> revLink;
        
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
                    sum == targetSum) {
                    // Found the target sum. Then trace the 
                    // reverse link using the hash map
                    ans.emplace_back(traceTreeNodes(currNode, revLink));
                } else {
                    // Check along the left subtree
                    if (currNode->left) {
                        nodes.push(currNode->left);
                        sums.push(sum);
                        revLink[currNode->left] = currNode;
                    }

                    // Check along the right subtree
                    if (currNode->right) {
                        nodes.push(currNode->right);
                        sums.push(sum);
                        revLink[currNode->right] = currNode;
                    }
                }
                nodes.pop();
                sums.pop();
            }
        }
        
        return ans;
    }
private:
    vector<int> traceTreeNodes(TreeNode* leaf, 
                               unordered_map<TreeNode*, TreeNode*>& revLink) {
        vector<int> link;
        while (leaf) {
            link.emplace_back(leaf->val);
            leaf = revLink[leaf];
        }
        reverse(link.begin(), link.end());
        return link;
    }
};