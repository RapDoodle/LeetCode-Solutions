class Solution {
public:
    /* Merge sort */
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<int> temp(n);
        reversePairsRecursive(nums, 0, n-1, temp, cnt);
        return cnt;
    }

private:
    void reversePairsRecursive(vector<int>& nums, 
        int lo, int hi, vector<int>& temp, int& cnt) {
        if (lo >= hi)
            return;
        
        // Recursively divide and sort with merge sort
        int m = lo + (hi-lo) / 2;
        reversePairsRecursive(nums, lo, m, temp, cnt);
        reversePairsRecursive(nums, m+1, hi, temp, cnt);

        int i = lo, j = m + 1;
        while (i <= m) {
            // Because [lo, m] and [m+1, hi] are sorted
            // respectively, once j points to a number
            // that violates nums[i] > 2*nums[j], all
            // numbers to the right of j also violates
            // the condition.
            while (j <= hi && (long) nums[i] > 2*(long) nums[j])
                ++j;
            
            // Calculate the number of elements between 
            // [mid+1, hi] that satisfy 
            //  nums[i] > 2*nums[j]
            // Note: -1 for one additional ++j
            cnt += (j - m - 1);  

            ++i;
        }

        // Merge the two sorted subarray [lo, m] 
        // and [m+1, hi]
        int k = lo;
        i = lo, j = m + 1;
        while (i <= m && j <= hi)
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        while (i <= m)
            temp[k++] = nums[i++];
        while (j <= hi)
            temp[k++] = nums[j++];
        
        // Copy back to nums
        k = lo;
        while (k <= hi)
            nums[k++] = temp[k];
    }
};