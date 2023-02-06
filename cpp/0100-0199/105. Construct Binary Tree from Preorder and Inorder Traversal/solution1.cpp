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
        // Observations:
        //  1. The first element in preorder traversal is always
        //     the root node.
        //  2. By locating the root node's index i in inorder traversal,
        //     we can determine portions of the left subtree ([lo, i-1])
        //     and portions of the right subtree ([i+1, hi])
        //  3. The above two observations are also true for each subtree.
        int n = inorder.size();

        // Create a hash map for quick index lookup
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        
        // Recursively build the tree starting from the root node
        return buildSubtree(preorder, inorder, index, 0, n-1, 0, n-1);
    }
    
private:
    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, 
                           const unordered_map<int, int>& index,
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
        
        // Locate the position of the root node in inorder traversal
        int nodeIdx = index.find(preorder[preorderBeginIdx])->second;
        
        // Calculate the size of the left-subtree
        int leftSubtreeSize = nodeIdx - inorderBeginIdx;
        
        // Recursively construct the left-subtree and right-subtree
        curr->left = buildSubtree(preorder, inorder, index, 
                                  preorderBeginIdx+1, preorderBeginIdx + leftSubtreeSize, 
                                  inorderBeginIdx, nodeIdx-1);
        curr->right = buildSubtree(preorder, inorder, index, 
                                   preorderBeginIdx+leftSubtreeSize+1, preorderEndIdx, 
                                   nodeIdx+1, inorderEndIdx);
        return curr;
    }
};