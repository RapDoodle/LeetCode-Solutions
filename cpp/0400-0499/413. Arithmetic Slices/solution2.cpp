class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        // For example: [1,2,3,4,5,8,9,10,11,15]
        //  [1,2,3], [2,3,4], [3,4,5]
        //  [1,2,3,4], [2,3,4,5]
        //  [1,2,3,4,5]
        //  [8,9,10], [9,10,11]
        //  [8,9,10,11]
        //  => 3 + 2 + 1 + 2 + 1 = 9
        int prev = 0, sum = 0;
        for (int i = 2; i < n; ++i)
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                sum += ++prev;
            else
                prev = 0;
        return sum;
    }
};