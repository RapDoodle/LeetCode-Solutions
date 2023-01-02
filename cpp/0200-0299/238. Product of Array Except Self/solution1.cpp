class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Prefix sum from the left
        vector<int> lSum(n);

        // Prefix sum from the right
        vector<int> rSum(n);

        // The product of lSum and rSum
        vector<int> prod(n);
        
        // Base cases
        lSum[0] = 1;
        rSum[n-1] = 1;

        for (int i = 1; i < n; ++i) {
            // Prefix sum from left to right,
            // up to (i-1)-th position
            lSum[i] = lSum[i-1] * nums[i-1];

            // Prefix sum from right to left
            // up to (n-i-1)-th position
            int r = n - i;
            rSum[r-1] = rSum[r] * nums[r];
        }

        // Find the product of lSum and rSum
        for (int i = 0; i < n; ++i)
            prod[i] = lSum[i] * rSum[i];

        return prod;
    }
};