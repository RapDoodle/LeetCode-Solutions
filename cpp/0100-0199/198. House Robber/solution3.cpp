class Solution {
public:
    /* Divide-and-Conquer */
    int rob(vector<int>& nums) {
        return dac(nums, 0, nums.size()-1);
    }
private:
    int dac(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        
        // Two scenarios:
        //  1. Skip the house in the middle
        //  2. Rob the house in the middle
        int mid = (i + j) >> 1;
        return max(dac(nums, i, mid-1) + dac(nums, mid+1, j),
                   dac(nums, i, mid-2) + nums[mid] + dac(nums, mid+2, j));
    }
};