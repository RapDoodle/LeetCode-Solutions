class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> perm;
        vector<vector<int>> ans;
        
        // Create a hash map that keeps track of the 
        // occurrences of each digit
        unordered_map<int, int> count;
        for (const auto num : nums)
            if (count.find(num) == count.end())
                count[num] = 1;
            else
                ++count[num];
        
        backtrack(perm, count, ans, nums.size());
        
        return ans;
    }

private:
    void backtrack(vector<int>& perm, unordered_map<int, int>& count, 
                   vector<vector<int>>& ans, const int len) {
        // Reached the maximum depth
        if (perm.size() == len) {
            ans.push_back(perm);
            return;
        }
        
        // For each level, only use distinct elements (the keys of 
        // the hash map). This avoids creating the same subtree, which
        // leads to duplicate results. For example, nums = [1,1,2].
        // If we were to use the two 1s, we get duplicate paths
        //            1             1             2
        //           / \           / \            | 
        //          1   2         1   2           1
        //         /     \       /     \          |
        //        2       1     2       1         1
        // Therefore, at each level, only distinct digits are used.
        for (const auto& kv : count) {
            if (kv.second > 0) {
                perm.push_back(kv.first);
                --count[kv.first];
                
                backtrack(perm, count, ans, len);

                ++count[kv.first];
                perm.pop_back();
            }
        }
    }
};