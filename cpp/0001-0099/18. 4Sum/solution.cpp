class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        // Handle nums.length <= 3
        if (nums.size() <= 3)
            return ans;
        
        // Sort the vector to better handle duplicates
        sort(nums.begin(), nums.end());
        
        // Four sum
        int m = nums.size();
        for (int a = 0; a < m - 3; ++a) {
            // Skip duplicates. Only use the left-most element in the 
            // presence of elements with the same value
            if (a > 0 && nums[a] == nums[a - 1])
                continue;  
            
            // Three sum
            for (int b = a + 1; b < m - 2; ++b) {
                if (b > 1 && b - a > 1 && nums[b] == nums[b - 1])
                    continue;
                
                // The two-pointers approach
                int c = b + 1, d = m - 1;
                
                while (c < d) {
                    // To avoid overflow in cases like:
                    // [0,0,0,1000000000,1000000000,1000000000,1000000000]
                    long sum = static_cast<long>(nums[a]) 
                        + static_cast<long>(nums[b]) 
                        + static_cast<long>(nums[c]) 
                        + static_cast<long>(nums[d]);
                    
                    if (sum == target) {
                        vector<int> v{nums[a], nums[b], nums[c], nums[d]};
                        ans.push_back(v);
                        
                        do {
                            ++c;
                        } while (c < d && nums[c] == nums[c - 1]);
                    } else if (sum > target) {
                        // The sum is too large
                        // reduce the sum by moving d to the left
                        d--;
                    } else {
                        // The sum is too small
                        // increase the sum by moving c to the right
                        ++c;
                    }
                }
            }
        }
        return ans;
    }
};