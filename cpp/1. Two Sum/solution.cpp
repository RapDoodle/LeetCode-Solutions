class Solution {
public:
    /* The brute force approach */
    vector<int> twoSum(vector<int>& nums, int target) {
        int y;
        vector<int> v;
        for (int i=0; i<nums.size()-1; i++) {
            y = target - nums[i];
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] == y) {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;  // Return an empty vector
    }
};