class Solution {
public:
    /* Greedy
     * Credits: https://youtu.be/TU0wOhE_3lw (explained in Chinese) 
     */
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return true;
        
        int modify = 0;
        for (int i = 1; i < n; ++i) {
            // Verify for non-decreasing order
            if (nums[i] >= nums[i-1])
                continue;
            
            // nums[i] < nums[i-1], violates the non-decreasing rule
            if (i-2 >= 0 && nums[i-2] > nums[i]) {
                /*     i-1                  i
                 *      /\               /---
                 *  ---/  \     ->   ---/
                 *         \
                 *    i-2  i        i-2 i-1
                 */
                nums[i] = nums[i-1];
            } else {
                /* i-2 < 0 && nums[i-2] <= nums[i] && nums[i-1] > nums[i]
                 * The case for i < 2 is considered here as the case does
                 * not concern the value of nums[i-2]
                 *      i            i
                 * i-2  /            /
                 *  \  /   ->    ---/
                 *   \/        i-2 i-1
                 *   i-1      
                 */
                nums[i-1] = nums[i];
            }
            ++modify;
            
            if (modify > 1)
                return false;
        }
        
        return true;
    }
};