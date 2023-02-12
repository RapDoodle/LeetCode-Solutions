class Solution {
public:
    /* Sorting */
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1, maxCount = 1, maxVal = nums[0], n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                ++cnt;
                if (cnt > maxCount) {
                    maxCount = cnt;
                    maxVal = nums[i];
                }
            } else {
                cnt = 1;
            }
        }
        return maxVal;
    }
};