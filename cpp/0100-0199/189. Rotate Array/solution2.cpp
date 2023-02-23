class Solution {
public:
    /* Constant memory */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = n-1;
        k = k % n;
        // Reverse the enitre array
        //    [0,1,2,3,4,5]
        // => [5,4,3,2,1,0]
        while (i < j)
            swap(nums[i++], nums[j--]);
        
        // Reverse [0..k-1] and [k, n-1] respectively
        // => [5,4,3,2,1,0]
        // => [5,4,3,2,1,0]
        i = 0;
        j = k-1;
        while (i < j)
            swap(nums[i++], nums[j--]);
        i = k;
        j = n-1;
        while (i < j)
            swap(nums[i++], nums[j--]);
    }
};