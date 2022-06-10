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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a hash map for quick lookup (index in inorder)
        int n = inorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        
        // Recursively build the tree starting from the root node
        return buildSubtree(preorder, inorder, index, 0, n-1, 0, n-1);
    }
    
private:
    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, 
                           unordered_map<int, int>& index,
                           int preorderBeginIdx, int preorderEndIdx, 
                           int inorderBeginIdx, int inorderEndIdx) {
        if (inorderBeginIdx > inorderEndIdx)
            return nullptr;
        
        if (inorderBeginIdx < 0 || inorderBeginIdx >= inorder.size())
            return nullptr;
        
        if (inorderEndIdx < 0 || inorderEndIdx >= inorder.size())
            return nullptr;
        
        // Instantiate the current node
        TreeNode* curr = new TreeNode(preorder[preorderBeginIdx]);
        
        // Locate the position of the current node in the inorder list
        int nodeIdx = index[preorder[preorderBeginIdx]];
        
        // Calculate the size of the left-subtree
        int leftSubtreeSize = nodeIdx - inorderBeginIdx;
        
        // Construct the left-subtree and right-subtree
        curr->left = buildSubtree(preorder, inorder, index, 
                                  preorderBeginIdx+1, preorderBeginIdx + leftSubtreeSize, 
                                  inorderBeginIdx, nodeIdx-1);
        curr->right = buildSubtree(preorder, inorder, index, 
                                   preorderBeginIdx+leftSubtreeSize+1, preorderEndIdx, 
                                   nodeIdx+1, inorderEndIdx);
        return curr;
    }
};