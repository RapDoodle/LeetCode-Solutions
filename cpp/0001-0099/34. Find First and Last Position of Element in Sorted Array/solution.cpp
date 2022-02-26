class Solution {
public:
    /* Binary search */
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find the lower bound of the target
        int lower = firstPosition(nums, target);
        
        // Find the upper bound of the target by first looking
        // for the first position of target + 1.
        int upper = firstPosition(nums, target + 1) - 1;
        if (lower <= upper)
            return {lower, upper};
        else
            return {-1, -1};
    }
    
    int firstPosition(vector<int>& nums, int target) {
        // lower: Whether or not to look for the lower bound.
        //  Otherwise, look for the upper bound
        int l = 0, r = nums.size() - 1, idx = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] >= target) {
                // Even if target + 1 does not exist, the value to 
                // the right of target's upper bound is returned 
                // because the left pointer will continue to move
                // to mid + 1 when nums[mid] < target.
                // For example: target = 8, and input = [5,7,7,8,8,10]
                // When mid = 4, l = 3, r = 5, because 8 < 9, 
                // l = mid + 1 => nums[l] = 10. 
                // 10 > 9, idx = 5, r = 5 - 1. l > r, the loop breaks.
                idx = mid;
                
                // Value is too large, try to reduce the number
                r = mid - 1;
            } else {
                // Value is too small, try to increase the number
                l = mid + 1;
            }
        }
        
        return idx;
    }
};