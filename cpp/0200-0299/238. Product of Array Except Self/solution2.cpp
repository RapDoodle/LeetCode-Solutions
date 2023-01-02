class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n);
        
        // Base cases
        prod[0] = 1;
        int r = 1;

        // Prefix sum from left to right, up to 
        // (i-1)-th position
        for (int i = 1; i < n; ++i)
            prod[i] = prod[i-1] * nums[i-1];

        // Prefix sum from right to left
        for (int i = n-1; i >= 0; --i) {
            prod[i] = prod[i] * r;
            r = r * nums[i];
        }

        return prod;
    }
};