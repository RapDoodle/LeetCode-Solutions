class Solution {
public:
    /* Binary search */
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        // Exactly one element only appears once means
        // every number to the left must start from an 
        // EVEN index and end on an ODD index, and
        // every number to the right start from an ODD
        // index and end on an EVEN index. Thus, use
        // binary search to look for such a value
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid % 2 == 0) {
                // Check whether mid and mid+1 contains
                // identical values that start from an 
                // EVEN index and end on an ODD index.
                if (nums[mid] == nums[mid+1]) {
                    // Example:
                    //  [0,0,1,1,2], mid = 2
                    //   l  mid  r
                    l = mid + 2;
                } else {
                    // nums[mid] != nums[mid+1]
                    // Example:
                    //  [0,0,1,2,2], mid = 2
                    //   l  mid  r
                    r = mid - 1;
                }
            } else {
                // Check whether mid and mid-1 contains
                // identical values that start from an 
                // EVEN index and end on an ODD index.
                if (nums[mid] == nums[mid-1]) {
                    // Example:
                    //  [0,0,1,1,2,2,3], mid = 3
                    //   l    mid    r
                    l = mid + 1;
                } else {
                    // Example:
                    //  [0,0,1,2,2,3,3], mid = 3
                    //   l    mid    r
                    r = mid - 1;
                }
            }
        }
        
        return nums[r+1];
    }
};