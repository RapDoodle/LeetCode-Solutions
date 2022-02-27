class Solution {
public:
    /* Binary search */
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) 
                return mid;
            
            if (nums[mid] >= nums[l]) {
                // In the left sorted portion
                if (target > nums[mid] || target < nums[l]) {
                    // Search in the right portion
                    // Case 1: target > nums[mid]
                    //  [4,5,6,7,8,0,1], target = 8
                    //   l    mid    r
                    // 
                    // Case 2: target < nums[l]
                    //  [4,5,6,7,8,0,1], target = 1
                    //   l    mid    r
                    l = mid + 1;
                } else {
                    // target < nums[mid] && target > nums[l]
                    // Search in the left portion
                    // Example:
                    //  [4,5,6,7,8,0,1], target = 5
                    //   l    mid    r 
                    r = mid - 1;
                }
            } else {
                // nums[mid] < nums[l]
                // In the right sorted portion
                if (target < nums[mid] || target > nums[r]) {
                    // Search in the left portion
                    // Case 1: target < nums[mid]
                    //  [5,6,7,0,1,2,3,4], target = 3
                    //         l  mid  r
                    // 
                    // Case 2: target > nums[r] 
                    //  [5,6,7,0,1,2,3,4], target = 6
                    //   l    mid      r
                    r = mid - 1;
                } else {
                    // target > nums[mid] && target < nums[r]
                    // Search in the right portion
                    // Example:
                    //  [5,6,7,0,1,2,3,4], target = 3
                    //   l    mid      r
                    l = mid + 1;
                }
            }
        }
        
        
        // Not found
        return -1;
    }
}; 