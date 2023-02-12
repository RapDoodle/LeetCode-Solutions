class Solution {
public:
    /* Hash map */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> c;
        int maxCount = 0, maxVal = 0;
        for (const int& num : nums) {
            if (c.find(num) == c.end())
                c[num] = 1;
            else
                ++c[num];
            if (c[num] > maxCount) {
                maxCount = c[num];
                maxVal = num;
            }
        }
        return maxVal;
    }
};