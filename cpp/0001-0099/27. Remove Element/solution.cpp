class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int i = -1, j = 0;
        while (j < n) {
            if (nums[j] == val) {
                ++j;
                continue;
            }
            if (j - i >= 2) {
                nums[i + 1] = nums[j];
            }
            ++i;
            ++j;
        }
        
        return i + 1;
    }
};