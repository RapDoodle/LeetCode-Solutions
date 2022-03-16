class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Odd numbers cannot be divided into equal halves
        if (sum % 2 != 0)
            return false;
        
        int target = sum / 2, n = nums.size();
        
        // Use a set to check existence of values in O(1)
        set<int> dp;
        
        // Use a vector to preserve the order of insertion
        vector<int> sums;
        
        // Calculate the sum of every possible combination
        dp.insert(0);
        sums.push_back(0);
        for (int i = 0; i < n; ++i) {
            // Only look at the exisiting values up to the
            // current moment
            int sumsSize = sums.size();
            for (int j = 0; j < sumsSize; ++j) {
                int sum = nums[i] + sums[j];
                
                // A match
                if (sum == target)
                    return true;
                
                // Add the sum if it does not exist
                if (dp.find(sum) == dp.end()) {
                    dp.insert(sum);
                    sums.push_back(sum);
                }
            }
            
            // Add the curent value
            if (dp.find(nums[i]) == dp.end()) {
                dp.insert(nums[i]);
                sums.push_back(nums[i]);
            }
        }
        
        return false;
    }
};