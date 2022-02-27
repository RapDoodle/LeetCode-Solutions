class Solution {
public:
    int findMin(vector<int>& nums) {
        // Use binary search to look for the MINIMUM value
        int l = 0, r = nums.size() - 1, minVal = nums[0];
        while (l <= r) {
            // In a monotonically increasing interval,
            // the left-most value is the smallest value
            // in the interval.
            // NOTICE: We use nums[l] < nums[r] instead of 
            // nums[l] <= nums[r] to avoid U-shaped arrays
            // like [3,1,3]. In the mentioned array, we 
            // first check nums[0] == nums[2], which is
            // 3 == 3. The statement evaluates to true,
            // completely ignoring the 1 in the middle.
            if (nums[l] < nums[r]) {
                minVal = min(nums[l], minVal);
                break;
            }
            
            // Not a monotonically increasing interval,
            // crosses between the first and second sorted
            // portion.
            int mid = (l + r) / 2;
            minVal = min(nums[mid], minVal);
            if (nums[l] == nums[mid]) {
                // Example:
                //  [2,2,2,2,0,1,2]
                //   l    mid    r
                // We do not know when the 2s in the 
                // first portion of the array will end.
                // Thus, we first eliminate the first 
                // 2.
                ++l;
            } else if (nums[mid] == nums[r]) {
                // Example:
                //  [2,5,6,2,2,2,2]
                //   l    mid    r
                // Similarly, we do not know when the 2s in  
                // the second half of the array will end.
                // Thus, we first eliminate the last 
                // 2.
                --r;
            } else if (nums[l] <= nums[mid]) {
                // In the left-sorted portion. For example:
                //  [2,3,4,5,6,0,1]
                //   l    mid    r
                // Find the minimum value in [mid+1, r]
                l = mid + 1;
            } else {
                // nums[l] > nums[mid]
                // In the right-sorted portion. For example:
                //  [5,6,0,1,2,3,4]
                //   l    mid    r
                // Find the minimum value in [l, mid-1]
                r = mid - 1;
            }
        }
        
        return minVal;
    }
};