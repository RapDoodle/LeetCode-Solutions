class Solution {
public:
    int findMin(vector<int>& nums) {
        // In case of a monotonically increasing array, 
        // like [1,2,3,4,5], we simply return the first
        // element of the array.
        if (nums[0] <= nums[nums.size()-1])
            return nums[0];
        
        // Use binary search to look for the MAXIMUM number.
        // We compare nums[l] >= nums[0] because we are sure
        // that if the array contains a left-sorted portion
        // and a right-sorted portion, every value in the 
        // right-sorted portion will be smaller than nums[0].
        int l = 0, r = nums.size() - 1;
        while (l <= r && nums[l] >= nums[0]) {
            int mid = (l + r) / 2;
            if (nums[0] <= nums[mid]) {
                // Move to the right in search of
                // a larger number.
                // For example:
                //  [1,2,3,4,5,6,0]
                //   l    mid    r
                l = mid + 1;
            } else {
                // nums[0] > nums[mid]:
                // Already reached the largest number,
                // decrease the upper bound to look for
                // the largest number.
                // For example:
                //  [5,6,7,1,2,3,4]
                //   l    mid    r
                r = mid - 1;
            }
        }
        
        // Upon reaching the largest number, the algorithm
        // does not know it has reached the largest number.
        // Thus, it will increase the lower bound to mid + 1
        // in search for a larger value. The move violates
        // nums[l] >= nums[0], the for-loop breaks. The lower
        // bound points precisely at the smallest number.
        return nums[l];
    }
};