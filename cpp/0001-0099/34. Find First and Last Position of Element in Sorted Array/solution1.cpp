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

private:
    int firstPosition(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, idx = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] >= target) {
                // For upper bound search:
                // Even if target'=(target+1) does not exist,  
                // the value to the right of (target')'s upper 
                // bound will be returned because the left
                // pointer will continue to move to mid+1
                // when nums[mid] < target.
                // For example: target = 8, so target' = 9
                //  and input = [5,7,7,8,8,10]
                //               0 1 2 3 4 5
                // Here, we look for target = 8 + 1 = 9.
                // When l = 3, r = 5, l < r: 
                //  nums[mid] = nums[4] = 8 < 9, 
                //  l = mid + 1 = 5 => nums[l] = nums[5] = 10. 
                // Now: l == r:
                //  nums[mid] = nums[5] = 10 > 9, 
                //  idx = 5, r = 5 - 1 = 4, l = 5
                // Now: l > r: the loop ends.
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