class Solution {
public:
    /* Two (three) pointers */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // The pointer pointing to the end of nums1
        int i = m + n - 1;
        
        // The pointer for nums1
        --m;
        
        // The pointer for nums2
        --n;
        
        while (m >= 0 && n >= 0)
            nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        
        // If n >=0, it means every element in the original nums1 are 
        // stored in positions greater than the current i.
        while (n >= 0)
            nums1[i--] = nums2[n--];
        
        // There is no need for while (m >= 0) because all the remaining
        // elements in the original nums1 are already in the correct 
        // position. 
        // For example, nums1 = [1, 2, 3, 0, 0, 0], m = 3, 
        // nums2 = [4, 5, 6], n = 3.
        // After the first while loop, nums1 = [1, 2, 3, 4, 5, 6]. 
        // Even though m = 3, every element is already in the desired 
        // position
    }
};