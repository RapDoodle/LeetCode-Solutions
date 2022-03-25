class Solution {
public:
    /* Dynamic programming */
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], dpPrev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dpPrev = max(dpPrev + nums[i], nums[i]);
            maxSum = max(maxSum, dpPrev);
        }
        return maxSum;
    }
};