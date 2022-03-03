class Solution {
public:
    void backtrack(int start, vector<int>& nums, int n, int k, vector<vector<int>>& ans) {
        // When the size has reached the defined size k
        if (nums.size() == k) {
            ans.push_back(nums);
            return;
        }
        
        // Recursively form all the combinations
        for (int i = start; i <= n; ++i) {
            nums.push_back(i);
            
            // For the recursive call, start from i + 1
            backtrack(i + 1, nums, n, k, ans);
            nums.pop_back();
        }
        
        // If an invalid combination occurred. 
        // For example, n = 4, k = 3. The last valid 
        // combination is [2,3,4]. When backtracking
        // reached [2,4], the loop won't execute.
        // After the function ends, the last number 4
        // is popped from the list.
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> ans;
        
        // Start backtracking from 1
        backtrack(1, nums, n, k, ans);
        return ans;
    }
};