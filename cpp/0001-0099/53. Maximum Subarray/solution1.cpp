class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Reset the sum back to 0 when the  
            // sum became negative (a.k.a., 
            // negative array prefix).
            sum = max(sum, 0);
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};