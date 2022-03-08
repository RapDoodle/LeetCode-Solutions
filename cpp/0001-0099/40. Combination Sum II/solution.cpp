class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
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
        
        // In a sorted array, possible combinations can only
        // be found in indexes >= i.
        for (int j = i; j < candidates.size(); ++j) {
            // From [i, n], only choose unique values. This
            // ensures the subtree is unique and no duplicate
            // answer will be found. However, it is possible
            // to have identical values in the combination
            // as long as the input array contains duplicates.
            // We must start to check from i, since i-1 may
            // have the same value as i.
            if (j > i && candidates[j] == candidates[j-1])
                continue;
            
            // Backtrack
            comb.emplace_back(candidates[j]);
            dfs(j + 1, sum + candidates[j], comb, candidates, target, ans);
            comb.pop_back();
        }
    }
};