class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxProd = nums[0], dpMin = 1, dpMax = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                // Edge case: when nums[i] = 0, restart dpMin and dpMax
                // Avoid being set to 0. Otherwise, subsequent min or 
                // max will always be 0.
                dpMin = 1;
                dpMax = 1;
                maxProd = max(maxProd, 0);
            } else {
                // Register the original dpMin
                int temp = dpMin*nums[i];

                // Handle cases like [-2, 3, -4]. Where the greedy approach
                // fails. For instance, -2*3=-6. If we restart at 3, the 
                // maximum we can get is 3 instead of -2*3*-4=24.
                // Here, 24 is obtained by mulitiplying with the previous
                // minimum (-6).
                dpMin = min(nums[i], min(temp, dpMax*nums[i]));
                dpMax = max(nums[i], max(temp, dpMax*nums[i]));
                maxProd = max(maxProd, max(dpMin, dpMax));
            }
        }
        return maxProd;
    }
};