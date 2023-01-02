class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int m = nums.size();
        vector<vector<int>> ans;
        
        // Sort the array so that we can easily find duplicates
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < m - 2; i++) {
            // Skip duplicates. Only use the left-most element in the 
            // presence of elements with the same value
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            // Given x, move the left and right pointer to find
            // y and z such that x + y + z = 0
            int j = i + 1, k = m - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> v{nums[i], nums[j], nums[k]};
                    ans.emplace_back(v);
                    do {
                        j++;
                    } while (j < k && nums[j] == nums[j - 1]);
                } else if (sum > 0) {
                    // The sum is too large, need to reduce the sum
                    // Decrease k
                    k--;
                } else {
                    // The sum is too small, need to increase the sum
                    // Increase j
                    j++;
                }
            }
        }
        
        return ans;
    }
};