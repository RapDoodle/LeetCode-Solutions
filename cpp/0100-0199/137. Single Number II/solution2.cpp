class Solution {
public:
    /* Bit manipulation */
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (const int& num : nums) {
            ones = (ones^num) & (~twos);
            twos = (twos^num) & (~ones);
        }
        return ones;
    }
};