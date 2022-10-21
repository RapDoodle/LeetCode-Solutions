class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 1, currLen = 1;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] < nums[i+1]) {
                currLen++;
                maxLen = max(currLen, maxLen);
            } else {
                currLen = 1;
            }
        }
        return maxLen;
    }
};