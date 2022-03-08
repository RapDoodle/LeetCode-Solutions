class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        dfs(0, 0, comb, candidates, target, ans);
        return ans;
    }
private:
    void dfs(const int i, const int sum, vector<int>& comb, 
             const vector<int>& candidates, const int target, 
             vector<vector<int>>& ans) {
        if (sum == target) {
            ans.emplace_back(comb);
            return;
        }
        
        if (sum > target || i >= candidates.size())
            return;
        
        // Include the same number
        comb.emplace_back(candidates[i]);
        dfs(i, sum + candidates[i], comb, candidates, target, ans);
        comb.pop_back();
        
        // Do not include the same number
        dfs(i + 1, sum, comb, candidates, target, ans);
    }
};