class Solution {
public:
    /* Divide-and-Conquer */
    int maxSubArray(vector<int>& nums) {
        return dac(nums, 0, nums.size() - 1);
    }
private:
    int dac(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        
        int mid = left + ((right-left) >> 1);
        int lss = dac(nums, left, mid);
        int rss = dac(nums, mid+1, right);
        
        // Find the largest sum in the left-subarray
        int cssl = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            cssl = max(cssl, sum);
        }
        
        // Find the largest sum in the right-subarray
        int cssr = INT_MIN;
        sum = 0;
        for (int i = mid+1; i <= right; ++i) {
            sum += nums[i];
            cssr = max(cssr, sum);
        }
        int css = cssl + cssr;
        
        return max(css, max(lss, rss));
    }
};