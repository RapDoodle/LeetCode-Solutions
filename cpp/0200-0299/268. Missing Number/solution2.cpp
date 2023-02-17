class Solution {
public:
    /* Math */
    int missingNumber(vector<int>& nums) {
        // The number that did not subtract from
        // total is the missing number
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += i - nums[i];
        cnt += n;
        return cnt;
    }
};