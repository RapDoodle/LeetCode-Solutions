class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the index before the monotonically decreasing
        // interval (or, when viewed from the back, the 
        // index after the end of the monotonically increasing 
        // interval). For example:
        //
        //  index 0 1 2 3 4 5 6
        //  nums  6 2 1 5 4 3 0
        //            * |-----|
        //
        // [5, 4, 3, 0] is the segment in which it has no more
        // options to explore. Thus, we backtrack to the 
        // position right before this segment, and find the 
        // next possible permutation by selecting the next
        // possible element for index 2. 
        int n = nums.size(), i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1])
            --i;
        // When we select the next permutation, we select the
        // successor of the current number. For example, after
        // [1, 3, 2], we backtrack to the first position, and
        // select 2 as the first index.
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i])
                --j;
            // To ensure the last segment is still in 
            // monotonically  decreasing order, we simply swap 
            // the chosen index with the successor.
            swap(nums[i], nums[j]);
        }
        // Finally, we reverse the segment so that the segment
        // is now in increasing order. Now, there is no 
        // monotonically decreasing segment, and we have all
        // the remaining positions (in example 1, indices after
        // 2) to explore.
        reverse(nums.begin() + i + 1, nums.end());
    }
};