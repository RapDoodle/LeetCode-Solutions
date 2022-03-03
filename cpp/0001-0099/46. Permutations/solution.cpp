class Solution {
public:
    void backtrack(vector<int>& nums, int level, vector<vector<int>>& ans) {
        // Reached the maximum depth
        if (level == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        
        // Every number left to the level-th number are "finalized"
        // in the current and subsequent recursive calls
        for (int l = level; l < nums.size(); ++l) {
            // Swap the two number. 
            // For example, when nums = [1,2,3], level = 0, we get
            //  nums = [1,2,3], [2,1,3], and [3,2,1].
            // For [2,1,3], level = 1, we get
            //  nums = [2,1,3], [2,3,1].
            // In level 2, the base case is executed, appending
            //  the result to ans.
            // When l = level, it is equivalent to no swap.
            swap(nums[l], nums[level]);
            backtrack(nums, level+1, ans);
            
            // Revert to the state before swap
            swap(nums[l], nums[level]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
};