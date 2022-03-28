class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), val;
        
        // Use the vector nums as a hash map:
        // On the occurrence of a number, mark nums[value-1]
        // as negative.
        for (int i = 0; i < n; ++i) {
            // Get the original value (the value may be modified
            // to negative already)
            val = abs(nums[i]);
            
            // Mark the (val-1)-th position as negative
            nums[val-1] = min(nums[val-1], -nums[val-1]);
        }
        
        // Look for positive values and add it the ans
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                ans.push_back(i+1);
        
        return ans;
    }
};