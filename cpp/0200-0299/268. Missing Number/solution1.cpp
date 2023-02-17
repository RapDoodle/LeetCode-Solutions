class Solution {
public:
    /* Math */
    int missingNumber(vector<int>& nums) {
        // For [0, 1, 2, ..., n], there are n+1 
        // elements.
        // Sn = n(a_1+a_n)/2, a_1=0, a_n=n+1
        int n = nums.size(), total = (n*(n+1)) / 2;
        for (int i = 0; i < n; ++i)
            total -= nums[i];
        
        // The number that did not subtract from
        // total is the missing number
        return total;
    }
};