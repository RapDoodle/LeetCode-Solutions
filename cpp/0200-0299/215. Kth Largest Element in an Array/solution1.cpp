class Solution {
public:
    /*  Quick select */
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, n-k);
    }

private:
    int quickSelect(vector<int>& nums, const int l, const int r, const int k) {
        if (l == r)
            return nums[l];

        // Randomly select a piviot
        int randPiviotIdx = l + rand() % (r - l + 1);
        int piviotIdx = partition(nums, l, r, randPiviotIdx);
        
        if (piviotIdx == k)
            return nums[piviotIdx];
        else if (piviotIdx > k)
            // Recurse on the left subarray
            return quickSelect(nums, l, piviotIdx-1, k);
        else
            // Recurse on the right subarray
            return quickSelect(nums, piviotIdx+1, r, k);
    }

    int partition(vector<int>& nums, const int l, const int r, const int piviot) {
        swap(nums[piviot], nums[r]);
        int i = l, j = r - 1;
        do {
            while (nums[i] < nums[r] && i < r)  
                // nums[i] < piviot
                ++i;

            while (nums[j] >= nums[r] && j > l)
                // nums[i] >= piviot
                --j;

            if (i < j)
                swap(nums[i], nums[j]);
        } while (i < j);
        swap(nums[i], nums[r]);

        // Returns the index of the piviot
        return i;
    }
};