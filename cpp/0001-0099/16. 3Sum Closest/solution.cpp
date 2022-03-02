class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array, takes O(N log N)
        sort(nums.begin(), nums.end());
        
        // Start with the largest possible sum
        int m = nums.size();
        int ans = nums[m - 3] + nums[m - 2] + nums[m - 1];
        
        for (int i = 0; i < m - 2; ++i) {
            int j = i + 1, k = m - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    // Decrease sum by moving k to the left
                    --k;
                } else if (sum < target) {
                    // Increase sum by moving j to the right
                    ++j;
                }
                
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
            }
        }
        return ans;
    }
};