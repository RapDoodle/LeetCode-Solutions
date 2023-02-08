class Solution {
public:
    /* Two pointers */
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1;
        while (i < j && i < n && j > 0) {
            // If i points at an odd number and j points
            // at an even number, swap the two
            if (nums[i] % 2 == 1 && nums[j] % 2 == 0)
                swap(nums[i++], nums[j--]);

            // Stop when an odd number is found
            while (i < n && nums[i] % 2 == 0)
                ++i;

            // Stop when an even number is found
            while (j >= 0 && nums[j] % 2 == 1)
                --j;

        }
        return nums;
    }
};