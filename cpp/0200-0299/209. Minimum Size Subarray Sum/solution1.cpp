class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding window approach
        int currSum = 0, currLen = 0, minLen = INT_MAX;
        
        // i is the slow-moving pointer 
        // j is the fast-moving pointer
        int i = 0, j = -1, n = nums.size();
        while (++j < n) {
            // On each iteration, move the fast-moving 
            // pointer to the right by 1 unit
            currSum += nums[j];
            ++currLen;
            while (i <= j && currSum >= target) {
                // When currSum >= target, record the
                // minLen if necessary
                minLen = min(minLen, currLen);
                
                // Iteratively move the slow-moving pointer
                // to look for the minimum length
                currSum -= nums[i];
                ++i;
                --currLen;
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};