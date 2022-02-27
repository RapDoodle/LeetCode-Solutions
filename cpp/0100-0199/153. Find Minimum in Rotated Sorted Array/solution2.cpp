class Solution {
public:
    int findMin(vector<int>& nums) {
        // Use binary search to look for the MINIMUM value
        int l = 0, r = nums.size() - 1, minVal = nums[0];
        while (l <= r) {
            // In a monotonically increasing interval,
            // the left-most value is the smallest value
            // in the interval.
            if (nums[l] <= nums[r]) {
                minVal = min(nums[l], minVal);
                break;
            }
            
            // Not a monotonically increasing interval,
            // crosses between the first and second sorted
            // portion.
            int mid = (l + r) / 2;
            minVal = min(nums[mid], minVal);
            if (nums[l] <= nums[mid]) {
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